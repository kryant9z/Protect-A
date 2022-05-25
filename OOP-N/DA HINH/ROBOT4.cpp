
#include <iostream>
#include <string>

using namespace std;

class Robot{
    string Name, UserName;
    int LocationX, LocationY, EnergyLevel;
public:
    //get-set
    int getEnergyLevel(){
        return EnergyLevel;
        }
    
    //ktao - huy
    Robot(string _Name="Robot", string _UserName="Noname", int _LocationX=0  , 
        int _LocationY= 0 ,    int _EnergyLevel= 100){
         Name = _Name; UserName = _UserName;
         LocationX = _LocationX; LocationY = _LocationY; 
         EnergyLevel= _EnergyLevel;
    }
    Robot(const Robot &b) {
        Name = b.Name; UserName = b.UserName;
        LocationX = b.LocationX; LocationY = b.LocationY; 
        EnergyLevel= b.EnergyLevel;
    }
    //ham bo tro
    void Charge(){ EnergyLevel +=10; }
    bool Move(int direction){
        if(EnergyLevel <=0 || direction < 0 || direction > 3)
            return false;
        switch (direction){
            case 0: LocationX--; break;
            case 1: LocationX++; break;
            case 2: LocationY++; break;
            case 3: LocationY--; break;
        }
        return true;    
    }
    void Display(){
        cout<<"{"<<Name<<"}:{"<< UserName<< "}"<<endl;
        cout<<"("<<LocationX<<","<< LocationY<< ")"<<endl;
        cout<<EnergyLevel<<endl;
    }
    void UnCharge(int e=5){ EnergyLevel -=e; }
    
    //virtual void AllMove(int a[], int m){}
};
class AdaptiveRobot : public Robot{
public:
    AdaptiveRobot(string _Name="AdaptiveRobot", string _UserName="Noname", int _LocationX=0  , 
        int _LocationY= 0 ,    int _EnergyLevel= 100)
        : Robot(_Name, _UserName, _LocationX, _LocationY, _EnergyLevel){ }
    AdaptiveRobot(const AdaptiveRobot &b)
        : Robot(b){ }
};
int main(){
    int n; cin>> n;
    for(int i= 0; i<n;i++){
        string name, user;
        int x,y, e;
        //thong tin
        cin.ignore();
        getline(cin, name);
        getline(cin, user);
        cin>> e >> x >> y;
        //huong di chuye
        int a[10], m=0;
        while(true){
            cin>> a[m];
            if(a[m]== -1) break;
            m++;
        }
        //tao doi tuong
        if(name[0]=='A'){
            //adaptive
            AdaptiveRobot b(name, user, x,y,e);
            for(int j=0 ; j< m ; j++){
                if(a[j] == 4) b.Charge();
                else {
                    if( b.getEnergyLevel() > 50 ){
                        b.Move( a[j] );
                        b.Move( a[j+1] );
                        b.Move( a[j+2] );
                        b.UnCharge(12);
                        j+=2;
                    }else if( b.getEnergyLevel() > 30 ){
                        b.Move( a[j] );
                        b.Move( a[j+1] );
                        b.UnCharge(9);
                        j+=1;
                    }else {
                        b.Move( a[j] );
                        b.UnCharge(6);
                    }
                }
            }
            b.Display();
        }else {
            //robot
            Robot b(name, user, x,y,e);
            for(int j=0 ; j< m ; j++){
                if(a[j] == 4) b.Charge();
                else {
                    b.Move( a[j] );
                    b.UnCharge(5);
                }
            }
            b.Display();
        }
    }
    
    return 0;
}
