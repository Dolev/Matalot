#include <iostream>
#include "Family.h"
int main()
{
    Family Levi;
    Family Gefen("Gefen",3,125,9134.5,7578.3,5000);
    Levi.show();
    Gefen.setFamilyName("very long family name indeed");
    Gefen.show();
    Gefen.setFamilyName("Topaz");
    if(Gefen.isGreater()){
        cout<<"Mam is richer than Dad\n";
    }
    else{
        cout<<"Dad is richer than Mam\n";
    }
    cout<<"Gefen's Family saved "<<Gefen.saving()<<" shekls this month\n";
        Gefen.betterMonth(5000); 
        getchar();
        return(1);
}
    

