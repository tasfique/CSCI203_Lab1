//Name-Tasfique Enam
//Student ID- J16020825/5886429
//LabTask1

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    //Declaration of variables
    int UnitSold [4] [3]; //units sold array to hold the items sold.
    string DashCam[4]={"RS Pro with GPS", "Transcend Drive Pro", "H203 1080", "Pioneer"}; // array to store dash cam models
    string Branches[3]={"SJ", "PJ", "KL"}; // array to store branches name.
    int highest=0;
    int num=0;
    int DashCamModels=0;
    int highest2=0;

    int RowTotal[3] = {0};
    int ColTotal[4] = {0};

    int Price [4];
    Price[0] = 730;
    Price[1] = 850;
    Price[2] = 150;
    Price[3] = 350;

    //Asking for user input.
    for(int col=0; col<3; col++) { //nested for loop
        for(int row=0; row<4; row++) {
            cout << " Enter the amount for DashCam Model " << DashCam[row] << " from Branch " << Branches[col] << " - ";
            cin >> UnitSold[row][col];

            while ( UnitSold[row][col] < 0 )
            {
                cout << " Wrong input, try again. " << endl;
                cout << " Enter the amount for DashCam Model " << DashCam[row] << " from Branch " << Branches[col] << " - ";
                cin >> UnitSold[row][col];
            }
            RowTotal[col] = RowTotal[col] + UnitSold[row][col]*Price[row];
            ColTotal[row] = ColTotal[row] + UnitSold[row][col];
        }
    }
    //To display the highest value
    for(int col=0; col<3; col++) {
        if(RowTotal[col]>RowTotal[highest])
            highest=col;
                for(int row=0; row<4; row++) {
                    if(ColTotal[row]>RowTotal[highest])
                        highest2=row;
                }
    }
    cout << endl;
    cout << "Display of all the Information" << endl;

    //The display of the tabular table.
    cout<<"+********************+************+************+************+"<<endl;
    cout<<"| DashCam Model     | SJ Branch   | PJ Branch   | KL Branch |"<<endl;
    cout<<"+********************+************+************+************+"<<endl;

    for(int row=0; row<4; row++){
        for(int col=0; col<3; col++){
                if(col==0)
                {
                    cout << "|" << left << setw(20) << DashCam[row] << "|";
                    cout << left << setw(12) << UnitSold[row][col] << "|";
                }
                else
                    cout << left << setw(12) << UnitSold[row][col] << "|";
        }

    cout<<endl;
    cout<<"+*********************+************+***********+*************+"<<endl;
    }
    cout<<endl;

    //Display of total sales.
    for (int i=0; i<3; i++)
        cout << " Total Sales "<< Branches[i] << " RM " << RowTotal[i] << endl;

        //Display of the highest Sale
        cout << " The highest Sale figure " << RowTotal[highest] << " from Branch " << Branches[highest] << endl;

    //Display of the most popular Dash Cam.
    for (int j = 0; j < 4; ++j) {
        if(ColTotal[highest] == ColTotal[j])
            cout << " The most popular Dash Cam is " << DashCam[j] << " with units sold of " << ColTotal[j] << " units " << endl;
    }

    return 0;
}
