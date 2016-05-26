#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class CustomVector
{
public:
    vector <T> _vector;

    //Constructor
    CustomVector(vector<T> input);

    //Sorts item in ascending order
    CustomVector<T> operator<(CustomVector<T> &anotherVector);
    //Sorts item in descending order
    CustomVector<T> operator>(CustomVector<T> &anotherVector);

    //Prints out the vector
    void print(void);
};

//Constructor definition
template <typename T>CustomVector<T>::CustomVector(vector <T> input)
{
    this->_vector = input;
}



//Overloaded operator [sorts item in ascending order]
template <typename T> CustomVector<T> CustomVector<T>::operator < (CustomVector<T> &customVector)
{
    std::sort(customVector._vector.begin (), customVector._vector.end ());
    return customVector;
}

//Overloaded operator [sorts item in descending order]
template <typename T> CustomVector<T> CustomVector<T>::operator > (CustomVector<T> &customVector)
{
    std::sort(customVector._vector.rbegin (), customVector._vector.rend ());
    return customVector;
}


//Prints out the vector
template <typename T> void CustomVector<T>::print ()
{
    for (T t : this->_vector) cout << t << endl;
}

int main()
{
    //Example vectors
    vector <int> test_ints({5, 1, 9, 2, 0, 3});
    vector <float> test_floats({1.00, 2.0, 0.5, 6.7, 9.0});

    //Creating CustomVectors
    CustomVector <int> int_custom_vectors(test_ints);
    CustomVector <float> float_custom_vectors(test_floats);

    cout << "----- UNSORTED INTS -----" << endl;
    int_custom_vectors.print ();
    cout << endl << endl;
    cout << "----- UNSORTED FLOATS ---- " << endl;
    float_custom_vectors.print ();
    cout << endl << endl;

    //Sorting in ascending order
    CustomVector <int> ascending_sorted_ints = ascending_sorted_ints < int_custom_vectors;
    CustomVector <float> ascending_sorted_floats = ascending_sorted_floats < float_custom_vectors;

    cout << "------ ASCENDING SORTED VALUES ====== " << endl << endl;
    ascending_sorted_floats.print ();
    cout << "======= " << endl;
    ascending_sorted_ints.print ();

    //Sorting in descending order
    CustomVector <int> descending_sorted_ints = descending_sorted_ints > int_custom_vectors;
    CustomVector <float> descending_sorted_floats = descending_sorted_floats > float_custom_vectors;

    cout << "------ DESCENDING SORTED VALUES ====== " << endl << endl;
    descending_sorted_floats.print ();
    cout << "======= " << endl;
    descending_sorted_ints.print ();

}
