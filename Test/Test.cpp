#include <iostream>
#include <string>
#include <fstream>
#include <list>

struct Lamp
{
    std::string name;
    std::string type;
    int power;
    int lightFlow;
    int colorTemperature;
};

std::istream& operator>>(std::istream& is, Lamp& lamp)
{
    is >> lamp.name
        >> lamp.type
        >> lamp.power
        >> lamp.lightFlow
        >> lamp.colorTemperature;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Lamp& lamp)
{
    os << lamp.name << ' '
        << lamp.type << ' '
        << lamp.power << ' '
        << lamp.lightFlow << ' '
        << lamp.colorTemperature << '\n';
    return os;
}

bool operator==(const Lamp& a, const Lamp& b)
{
    return (a.name == b.name && a.type == b.type && a.power == b.power
        && a.lightFlow == b.lightFlow && a.colorTemperature == b.colorTemperature);
}

void print_lamps(const std::list<Lamp>& v_lamp)
{
    for (auto& elem : v_lamp)
        std::cout << "\nName: " << elem.name
        << "\nType: " << elem.type
        << "\nPower: " << elem.power
        << "\nLight flow: " << elem.lightFlow
        << "\nColor temperature: " << elem.colorTemperature
        << '\n';
}

std::list<Lamp> getAllProducts()
{
    std::list<Lamp> listOfLamps;
    std::ifstream sourceFile{ "products.txt" };
    if (!sourceFile)
        throw std::runtime_error("getAllProducts: cannot open the file\n"); //status code?

    for (Lamp tempLamp; sourceFile >> tempLamp;)
        listOfLamps.push_back(tempLamp);

    if (sourceFile.eof())
        std::cout << "getAllProducts: success\n"; //status code?
    else std::cout << "getAllProducts: fail\n"; //status code?
    return listOfLamps;
}

void deleteProduct(const Lamp& lamp)
{
    std::list<Lamp> listOfLamps;
    std::ifstream sourceFile{ "products.txt" };
    if (!sourceFile)
        throw std::runtime_error("deleteProduct: cannot open the source file\n"); //status code?

    for (Lamp tempLamp; sourceFile >> tempLamp;)
        listOfLamps.push_back(tempLamp);

    if (sourceFile.bad())
        std::cout << "deleteProduct: fail\n"; //status code?
    sourceFile.close();

    auto lampPosition = std::find(listOfLamps.begin(), listOfLamps.end(), lamp);
    if (lampPosition == listOfLamps.end())
    {
        std::cout << "deleteProduct: not found\n"; //status code?
        return;
    }
    else listOfLamps.erase(lampPosition);

    std::ofstream newFile{ "products.txt" };
    if (!newFile)
        throw std::runtime_error("deleteProduct: cannot open the destination file\n"); //status code?

    for (auto& elem : listOfLamps)
        newFile << elem;

    if (newFile.fail())
        std::cout << "deleteProduct: fail\n"; //status code?
    else std::cout << "deleteProduct: success\n"; //status code?
}

void postProduct(const Lamp& lamp)
{
    std::list<Lamp> listOfLamps;
    std::ifstream sourceFile{ "products.txt" };
    if (!sourceFile)
        throw std::runtime_error("postProduct: cannot open the file\n"); //status code?

    for (Lamp tempLamp; sourceFile >> tempLamp;)
        listOfLamps.push_back(tempLamp);

    if (sourceFile.bad())
        std::cout << "postProduct: fail\n"; //status code?
    sourceFile.close();

    auto lampPosition = std::find(listOfLamps.begin(), listOfLamps.end(), lamp);
    if(lampPosition != listOfLamps.end())
    {
        std::cout << "postProduct: already exist\n"; //status code?
        return;
    }

    listOfLamps.push_back(lamp);

    std::ofstream newFile{ "products.txt" };
    if (!newFile)
        throw std::runtime_error("postProduct: cannot open the destination file\n"); //status code?

    for (auto& elem : listOfLamps)
        newFile << elem;

    if (newFile.fail())
        std::cout << "postProduct: fail\n"; //status code?
    else std::cout << "postProduct: success\n"; //status code?
}

void patchProduct(const Lamp& lamp)
{
    std::list<Lamp> listOfLamps;
    std::ifstream sourceFile{ "products.txt" };
    if (!sourceFile)
        throw std::runtime_error("patchProduct: cannot open the file\n"); //status code?

    for (Lamp tempLamp; sourceFile >> tempLamp;)
        listOfLamps.push_back(tempLamp);

    if (sourceFile.bad())
        std::cout << "postProduct: fail\n"; //status code?
    sourceFile.close();

    auto lampPosition = std::find_if(listOfLamps.begin(), listOfLamps.end(),
        [&lamp](const Lamp& lmp)
        {
            return lamp.name == lmp.name;
        });

    if (lampPosition == listOfLamps.end())
    {
        std::cout << "patchProduct: not found\n"; //status code?
        return;
    }
    else (*lampPosition) = lamp;

    std::ofstream newFile{ "products.txt" };
    if (!newFile)
        throw std::runtime_error("postProduct: cannot open the destination file\n"); //status code?

    for (auto& elem : listOfLamps)
        newFile << elem;

    if (newFile.fail())
        std::cout << "postProduct: fail\n"; //status code?
    else std::cout << "postProduct: success\n"; //status code?

}

int main()
{
    std::list<Lamp> list{getAllProducts()};
    print_lamps(list);
    Lamp temp{ "ToDEL", "Indoor", 150, 500, 6400 };
    deleteProduct(temp);
    postProduct(temp);
    temp = { "ToDEL", "Indoor", 155, 520, 6500 };
    patchProduct(temp);
}
