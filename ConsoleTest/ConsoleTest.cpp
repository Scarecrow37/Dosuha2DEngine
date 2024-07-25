#include <unordered_map>

class A
{
    
};

int main(int argc, char* argv[])
{
    std::unordered_map<int, A> map;
    map[0] = A();
}
