#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

class MergeSort {
    vector<int> numList;
public:
    void fnGenRandArray(int);
    void fnDispArray();
    void fnSortArray();
    void fnMergeSort(int,int);
    void fnMerge(int,int,int);

};

int main()
{
    struct timespec tv;
    int iChoice,i,iNum;
    double dStart,dEnd;
    MergeSort myListObj;
    ofstream fout("Mergeplot.dat",ios::out);

    srand(time(NULL));

    FILE *gunplot=nullptr;

    do {
        cout << "\n1.Plot the graph \n2.MergeSort \n3.Exit \n";
        cout <<"\n Enter your choice:";
        cin >> iChoice;

        switch(iChoice) {
            case 1:
                    for( i =0;i<10000;i+=100) {
                        myListObj.fnGenRandArray(i);
                        clock_gettime=(CLOCK_REALTIME ,&tv);
                        dStart=tv.tv_sec+tv.tv_nsec / 1e9;
                        myListObj.fnSortArray();
                        clock_gettime=(CLOCK_REALTIME ,&tv);
                        dEnd=tv.tv_sec+tv.tv_nsec / 1e9;
                        fout<<i <<"\t" << setprecision(10) <<dStart - dEnd << endl;

                        cout<< "File is generated and stored in <Mergeplot.dat> \n";
                        gunplot=popen("gunplot --persist","w");
                        if(!gunplot) {
                            cerr <<"Error opening gnuplot";
                            return 1;

                        }
                        fprintf(gnuplot,"Plot 'Mergeplot.dat' using 1:2 line with value 'time Complexity' \n");
                        pclose(gnuplot);
                        break;

                    }

            case 2 :
                    cout << "\n Enter number of element to sort:";
                    cin >>iNum;
                    myListObj.fnGenRandArray(iNum);
                    cout << "Unsorted Array:";
                    myListObj.fnDispArray();
                    myListObj.fnSortArray();
                    cout<<"Sorted Array:";
                    myListObj.fnDispArray();
                    break;
            
            case 3 : fout.close();
                        exit(0);

            default : cout << "Invalid Choice! Please enter 1 , 2 or 3";
        }
        
    }
    while(true);

    return 0;
}

void MergeSort :: fnGenRandArray(int n){
    numList.clear();
    for(int i=0;i<n;i++) {
        numList.push_back(rand()%10000);

    }
} 

void MergeSort :: fnDispArray()
{
    for(int num : numList) {
        cout << num << endl;
    }

}

void MergeSort :: fnSortArray() {
    if(!numList.empty()) {
        fnMergeSort(0,numList.size()-1);
    }
}

void  MergeSort ::fnMergeSort (int left ,int right) {
    if(left<right) {
        int mid =left +(right-left)/2;
        fnMergeSort( left, right);
        fnMergeSort(mid+1,right);
        fnMerge(left,mid,right);
    }
}

void MergeSort :: fnMerge(int left,int mid , int right){
    vector<int> temp;
    int i=left,j=mid+1;

    while(i<=mid && i<=right) {
        if(numList[i] <= numList[j]) {
            temp.push_back(numList[i]);
            i++;
        }
        else {
            temp.push_back(numList[j]);
            j++
        }
    }

}