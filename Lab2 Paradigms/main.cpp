#include <iostream>
#include <set>
using namespace std;
class FunctionalObjects {
private:
    set<int> something;
public:
    set<int> GetSet(){
        return this->something;
    }
};
int main(){
    return 0;
}
