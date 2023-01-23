#include "RideTicket.cpp"
#include "driver.cpp"
#include <unistd.h>
#include <filesystem>
void Truck();
int main() {
Truck();
cout << "Are you a driver or a manager ? (D/M)" << endl;
char answer;
cin >> answer;
if (answer == 'D' || answer == 'd')
{
std::string name;
cout << "Hello there !" << endl << "Please state your name : " << endl;
cin >> name;
std::filesystem::path filePath(name+"Tickets.txt");
if(std::filesystem::exists(filePath))
{
Driver driver;
driver.setDriverName(name);
driver.ReadTicketsFromFile();
cout<<driver.getTicketsVec().size()<<"##########";
for(int i=0 ;i<=driver.getTicketsVec().size();i++)
{
driver.getLastTicket().displayTicket();
driver.getTicketsVec().pop_back();
}
return 0;
}
//driver.getLastTicket().displayTicket();
//return 0 ;
//}
// cout << "Hello " << name << " , Please enter your drivers license experation date : " << endl;
// int day , month, year ;  
// cout << "Day : " << endl;
// cin >> day;
// cout << "Month : "<< endl;
// cin >> month;
// cout << "Year : "<< endl;
// cin >> year; 
// Driver driver;
// driver.setDriverName(name);
// driver.setLicenseExpire(day, month, year);
// if (driver.isValidLicense()) {
// cout << "Driver's license is valid , you can drive ! " << endl << "Opening a new ticket for the ride .............. " << endl;
// driver.addNewTicket();

// cout << "Ride in progress ..." << endl << "press q to end ride" << endl;
// cin >> answer ; 
// if (answer == 'q' || answer == 'Q')
// {
// driver.closeOpendTicket();
// driver.getLastTicket().displayTicket();
// driver.WriteTicketsToFile();
// }
// }
}

return 0;
}
void Truck(){
    std::cout << "       _.--,_......----..__" << std::endl;
    std::cout << "       \\  .'          '    ```--...__      \\" << std::endl;
    std::cout << "        \\;           '            .  '.   ||" << std::endl;
    std::cout << "        :           '            '     \\ .''." << std::endl;
    std::cout << "      .';          : FleetManager'       .|  |.--..___" << std::endl;
    std::cout << "     /   \\         |           :        :|  /.------.\\" << std::endl;
    std::cout << "    /    .'._      :           |        ||  ||      |\\\\" << std::endl;
    std::cout << "   /.-. /|-| `-.               :        ;|  ||______|_\\`.______" << std::endl;
    std::cout << "  //  // |-|    \\   '           '      / |  ||='      | |      `." << std::endl;
    std::cout << " //  //\\|-|     `-._'           '   .'  |  ||        | |        \\" << std::endl;
    std::cout << "/.-.//  \\-|_________```------------` ___'. ||        | '_.--.   <)" << std::endl;
    std::cout << "'._.'  /  .-----.   .-----.   .''''''''.    |'--..____| /  _  \\   |" << std::endl;
    std::cout << "       |_/.'   '.\\_/.'   '.\\_[ [ [  ] ] ]___|_________.'.'   '.\\  ]" << std::endl;
    std::cout << "         :  .-.  : :  .-.  :  '........'    (_________):  .-.  :`-'" << std::endl;
    std::cout << "         :  '-'  : :  '-'  :                           :  '-'  :" << std::endl;
    std::cout << "          '._ _.'   '._ _.'                             '._ _.'" << std::endl;
}