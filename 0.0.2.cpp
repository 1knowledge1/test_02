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
    float *elements,*tmp_elements1,*tmp_elements2;
    int num, shift;

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
    if(!(cin>>shift)||(shift < 0) )
    {
        cout <<"An error has occured while reading input data.\n";
        return 0;
    }

    tmp_elements1 = new float [num-shift];
    for(int i=0, k = (num-shift-1); i<(num-shift); i++, k--){
        tmp_elements1[i] = elements[k];
    }

    tmp_elements2 = new float [shift];
    for(int i=(num-1), k = 0; i>=(num-shift); i--, k++){
        tmp_elements2[k] = elements[i];
    }

    for(int i = 0; i<(num-shift); i++){
        elements[i] = tmp_elements1[i];
    }
    for(int i=(num-shift), k = 0; i<num; i++, k++){
        elements[i] = tmp_elements2[k];
    }
    reverse(elements,num);

    for (int i = 0; i < num; i++) cout << elements[i]<<' ';

    delete[] elements;
    delete[] tmp_elements1;
    delete[] tmp_elements2;
    return 0;
}
