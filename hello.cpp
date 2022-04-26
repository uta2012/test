#include <iostream>


class Car
{
    public:
        Car(void);
        std::string color;
        std::string enging;
        float gas_tank;
        unsigned int wheel;
};


class Plan : public Car
{

};



Car::Car()
{
    color = "haha";
    enging = "V8";
}




int main()
{

    Car tank;
    tank.color = "white";
    tank.wheel = 4;




    int arr[10];

    for(int i = 0; i < 10; i++)
    {
        std::cin >> arr[i];
    }
    int sum = 0;

    for(int i = 0; i < 10; i++)
    {
        sum = arr[i] + sum;
    }

    std::cout << sum << std::endl;
    return 0;
}