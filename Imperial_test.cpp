

// test_Imperial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include<ctime>

using namespace std;

class Imperial_Test {
public:
    virtual void processData(int) = 0;
    virtual void printData(int) = 0;
    virtual ~Imperial_Test() {}
};

class S_class : public Imperial_Test {


public:
  
    void processData(int len) {

      

        srand(time(0));

       const int MAX = 50;
        const int l = 62;
        char AN_array[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
        char randArray[MAX];
        bool flag = false;
       
        for (int i = 0; i < len; i++)
        {
            randArray[i] = AN_array[rand() % l];
            if (randArray[i] == '0')
                flag = true;
        }



        cout << "Zero:" << boolalpha << flag << "String:";
        cout << "\"";

        for (int i = 0; i < len; i++)
        {

            cout << randArray[i];

        }
        cout << "\"";

    }



    void printData(int len) {


        processData(len);


        cout << "Message:" << "\"" << typeid(*this).name() << "\"";


    }
};
class D_class : public Imperial_Test {



public:
   

    void processData(int len) {


        srand(time(0));

        const int MAX = 50;

        double doubleArray[MAX];
        bool flag = false;


        for (int i = 0; i < len; i++)
        {

            doubleArray[i] = 10 * ((double)(rand()) + 1.) / ((double)(RAND_MAX)+1.);
            //  cout << doubleArray[i]<<" ";
            if (doubleArray[i] == 0.0)
                flag = true;

        }
        double Maximum = 0;

        for (auto const& dou : doubleArray)
            if (dou > Maximum)
                Maximum = dou;



        cout << "Zero:" << boolalpha << flag << "Maximum:" << Maximum;
    }


    void printData(int len) {

        processData(len);

        cout << "Message:" << "\"" << typeid(*this).name() << "\"";

    }
};

class I_class : public Imperial_Test {


public:

    

    void processData(int len) {


        srand(time(0));

        const int MAX = 50;

        int consecArray[MAX];
        bool flag = false;

        int step = 1 + rand() % 2;
        for (int i = 0; i <= 2 * len / step; i++)
        {

            consecArray[i] = -len + i * step;
            //  cout << consecArray[i];
            if (consecArray[i] == 0)
                flag = true;


        }


        cout << "Zero:" << boolalpha << flag << "Minimum:" << -len;
    }



    void printData(int len) {
        processData(len);
        cout << "Message:" << "\"" << typeid(*this).name() << "\"";
    }
};

int main()
{
    int length;
    cout << "Enter the length of array(Upper limit is Max 50: = " << endl;
    cin >> length;


    /*  Imperial_Test* classes[] = {new S_class,new D_class, new I_class};
      for (int i = 0; i < 3; i++)
          classes[i]->printData();*/


    vector <Imperial_Test*> classes;
    classes.push_back(new S_class());
    classes.push_back(new D_class());
    classes.push_back(new I_class());
    for (const auto& i : classes)
    {
        // i->processData(length);
        i->printData(length);
        delete i;
    }

    system("pause>0");
}


