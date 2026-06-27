#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v = {10, 20, 30, 40, 50};
    int X = 35;

    auto it = std::lower_bound(v.begin(), v.end(), X);

    if (it != v.begin()) {
        --it; // Rje3 l-l-lor
        std::cout << "Akbar 3onsour as-ghar qat3an mn 30 hwa: " << *it << std::endl; // Ghadi y-3tik 20
    } else {
        std::cout << "Ma-kayn hata 3onsour as-ghar mn " << X << std::endl;
    }
}