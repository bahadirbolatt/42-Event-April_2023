#include <iostream>
#include <string>

int get_base(int size) // calculate for the lowest base width
{
    int base = 7;
    int increment_by = 12;

    for (int increments = 1; increments < size; increments++)
    {
        base += increment_by;
        if (increments % 2 == 0)
            increment_by += 4;
        else
            increment_by += 2;
    }
    return (base);
}

void fill(int size, int floor, int width, int step) // draw the other lines
{
    // printf("size: %d\n", size);
    // printf("floor: %d\n", floor);
    // printf("width: %d\n", width);
    // printf("step: %d\n", step);
                           // kucuge yuvarlar
    int door_pos = (2 * ((floor - 1) / 2)) + 1; // hangi segmentte isen
    for (int pos = 0; pos < width; pos++)
    {
        if (pos == 0)
            std::cout << "/";
        else if (pos == width - 1)
            std::cout << "\\";
        else
        {                                       // 19  20  21                                              //step 0 baslar
            if (floor == size && pos >= (width - door_pos) / 2 && pos < (width + door_pos) / 2 && floor - step + 2 <= door_pos)
            {
                if (door_pos >= 5 && step == floor - (door_pos / 2) + 1 && pos == ((width + door_pos) / 2) - 2)
                    std::cout << "$";
                else
                    std::cout << "|";
            }
            else
                std::cout << "*";
        }
    }
    std::cout << std::endl;
}

// size: dışardan girilen değişken
// floor: piramidin kat sayısı
// width: şu anki çizdirilen satırın genişliği
// step: çizilen katın numarası. her floorda sıfırlanır
int main(int ac, char **av)
{
    if (ac != 2 || std::stoi(av[1]) < 1)
        return (0);
    int size = std::stoi(av[1]);
    int width = 1;
    for (int floor = 1; floor <= size; floor++)
    {
        for (int step = 0; step < floor + 2; step++)
        {
            // printf("step: %d\n", step);
            width += 2;
            for (int i = 0; i < (get_base(size) - width) / 2; i++)
                std::cout << " ";
            fill(size, floor, width, step);
        }
        width += (2 * ((floor - 1) / 2)) + 4;
    }
    return (0);
}