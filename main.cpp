#include <chrono>

/* Only needed for the sake of this example. */
#include <iostream>
#include <thread>
#include <fstream>
using namespace std;
int arr[10005];

void is_prime_one(){
    for(int x = 0; x<10000; x++){
       for(int i=2; i*i<=arr[x]; i++) if(arr[x]%i == 0) continue;
    }
}

void is_prime_two(){
    for(int x = 0; x<10000; x++){
       for(int i=2; i<=arr[x]/2; i++) if(arr[x]%i == 0) continue;
    }   
}

void is_prime_three(){
    for(int x=0; x<10000; x++){
        for(int i=2; i<=7; i++) if(arr[x]%i == 0) continue;
        for(int i=2; i*i*36<=arr[x]; i++) if(arr[x]%(6*i-1) == 0 || arr[x]%(6*i+1) == 0) continue;
    }
}



int main()
{
    ifstream fin("f.in");
    int x, index=0;
    while(fin>>x) arr[index++] = x;


	using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    is_prime_three();
    auto t2 = high_resolution_clock::now();


    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    duration<double, milli> ms_double = t2 - t1;

    cout << ms_int.count() << "ms\n";
    return 0;

}





