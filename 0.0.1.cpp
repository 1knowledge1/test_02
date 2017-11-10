#include <iostream>
#include <sstream>

using namespace std;

bool input(float * &elements, int num)
{
    float *tmp_elements;
    string str;
    int excess_el;

    getline(cin, str);

    tmp_elements = new float [num];

    for (string str; getline(cin, str); ) {
        istringstream stream(str);
        for (unsigned int j = 0; j < num; ++j) {
            if(!(stream >> tmp_elements[j])) {
                return false;
            }
        }
        if(stream >> excess_el) return false;
        break;
    }
    elements = tmp_elements;
    return true;
}

void reverse(float *elements, int num)
{
    for(int i = 0; i < (num/2); i++){
        swap(elements[i],elements[num-(i+1)]);
    }

}

int main() {
    float *elements;
    int num;

    if(!(cin>>num)||(num < 0) )
    {
        cout <<"An error has occured while reading input data.\n";
        return 0;
    }

    if(!(input(elements,num)))
    {
        cout <<"An error has occured while reading input data.\n";
        return 0;
    }

    reverse(elements, num);
    for (int i = 0; i < num; i++) cout << elements[i]<<' ';

    delete[] elements;
    return 0;
}
