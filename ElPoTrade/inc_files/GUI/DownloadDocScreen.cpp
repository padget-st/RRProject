#include "DownloadDocScreen.h"

DownloadDocScreen::DownloadDocScreen(const ItemDocument& doc, QWidget* wgt)
	: m_lbl_info{ new QLabel(doc.doc_name.c_str(), this) }, m_lbl_status{ new QLabel("Waiting for path", this) },
	m_line_path{ new QLineEdit("Enter path to save the file", this) },
	m_pb_path{ new QPushButton("Browse..", this) }, m_pb_close{ new QPushButton("Close", this) },
	m_pb_download{ new QPushButton("Download", this) }, m_doc{ doc }
{
	setAttribute(Qt::WA_DeleteOnClose);

	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));
	connect(m_pb_path, SIGNAL(clicked()), SLOT(slotBrowsePath()));
	connect(m_pb_download, SIGNAL(clicked()), SLOT(slotDownloadDoc()));

	std::unique_ptr<QHBoxLayout> horiz_lay = std::make_unique<QHBoxLayout>();
	horiz_lay->addWidget(m_line_path);
	horiz_lay->addWidget(m_pb_path);
	horiz_lay->addWidget(m_pb_download);
	
	QVBoxLayout* vert_lay = new QVBoxLayout(this);
	vert_lay->addWidget(m_lbl_info);
	vert_lay->addLayout(horiz_lay.release());
	vert_lay->addWidget(m_lbl_status);
	vert_lay->addWidget(m_pb_close);

	setLayout(vert_lay);
}

void DownloadDocScreen::slotBrowsePath()
{
	m_line_path->setText(QFileDialog::getSaveFileName(this, "Save file to", m_doc.doc_name.c_str(), "*.pdf"));
}

void DownloadDocScreen::slotDownloadDoc()
{
	ResourceManager rm;
	std::vector<unsigned char> v_doc{ rm.get_doc(m_doc.doc_url) };

	std::ofstream out_file{ m_line_path->text().toStdString(), std::ios::binary };
	if(!out_file)
	{
		throw std::runtime_error("Can't download the file");
	}

	try
	{
		out_file.write(reinterpret_cast<char*>(v_doc.data()), v_doc.size() * sizeof(unsigned char));
		m_lbl_status->setText("Successfully downloaded");
	}
	catch (std::exception& e)
	{
		m_lbl_status->setText(e.what());
	}
}
