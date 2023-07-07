#include <iostream>
#include <fstream>

using namespace std;

const int MAXTICKETS = 200;

typedef struct guest
{
    string guestName;
    int dni;
    int ticketNumber;
    bool attendance = false;

} guest;

typedef guest guests[MAXTICKETS];

void menu();
guest addGuests(int tTicketNumber);
void editGuest(guests& tGuests, int tDNI, int invitations);
void deleteGuest(guests& tGuests, int tDNI, int invitations);
void listGuests(guests& tGuests, int invitations);
void isComing(guests& tGuest, int tDNI, int invitations);
void editAttendance(guests& tGuests, int tDNI, int invitations);
void save(guests& tGuests, int invitations);




int main()
{
    
    menu();
    
    return 0;
}

void menu()
{
    int i = 1;
    int sentedInvitations = 0;
    int choice = 0;
    int guestDNI = 0;
    guests Guests;
    

    while (choice != 7)
    {   
        cout << "Sistema de gestion de invitados" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Ingresar nuevo invitado." << endl;
        cout << "2. Editar invitado." << endl;
        cout << "3. Eliminar invitado." << endl;
        cout << "4. Confirmar invitacion." << endl;
        cout << "5. Editar asistencia." << endl;
        cout << "6. Listar invitados." << endl;
        cout << "7. Cerrar el programa." << endl;
        cout << "--------------------------------" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:{

            char add = '1'; // use una variable tipo char para que no devuelva error en caso de que un usuario ingrese un otro valor que 1 o 2 
            do
                {
                    Guests[i] = addGuests(i);
                    cout << "Ingrese 1 para volver a enviar una invitación, de lo contrario ingrese cualquier otro caracter: ";
                    cin >> add;
                    sentedInvitations++;
                    i++;
                } while (add == '1');
            break;
            
        }
        case 2:
        {
            cout << "Ingrese el DNI del invitado a editar: ";
            cin >> guestDNI;
            editGuest(Guests, guestDNI, sentedInvitations);
            
            break;
        }
        case 3:
        {
            cout << "Ingrese el DNI del invitado a borrar: ";
            cin >> guestDNI;
            deleteGuest(Guests, guestDNI, sentedInvitations);
            break;
        }
        case 4:
        {
            cout << "Ingrese el DNI para saber si ha confirmado la asistencia: ";
            cin >> guestDNI;
            isComing(Guests, guestDNI, sentedInvitations);
            break;
        }
        case 5:
        {
            cout << "Ingrese el DNI para editar asistencia: ";
            cin >> guestDNI;
            editAttendance(Guests, guestDNI, sentedInvitations);
            break;
        }
        case 6:
        {
            listGuests(Guests, sentedInvitations);
                       
            break;
        }
        case 7:
        {
            save(Guests, sentedInvitations);
            cout << "Gracias por utilizar nuestro programa." << endl;
            break;
        }
        default:
            cout << "La opcion ingresada no es valida." << endl;
            break;
        }
    }
    
};



guest addGuests(int tTicketNumber)
{

    guest tGuest;

    cout << "Ingrese nombre del invitado: ";
    cin.ignore(); // limpia el buffer
    getline(cin, tGuest.guestName);
    cout << "\n Ingrese DNI del invitado: ";
    cin >> tGuest.dni;
    cout << "\n ¿Ha confirmado asistencia?\n 1. Si\n 0. No";
    cin >> tGuest.attendance;
    tGuest.ticketNumber = tTicketNumber + 100;
    return tGuest;
}

void editGuest(guests& tGuests, int tDNI, int invitations)
{

    for (int i = 1; i < invitations; i++)
    {
        if (tDNI == tGuests[i].dni)
        {   
            cout << "\n Ingrese nuevo DNI: ";
            cin >> tGuests[i].dni;
            cout << "\n Ingrese nuevo nombre: ";
            cin >> tGuests[i].guestName;
            cout << "\n Ha confirmado asistencia: (Ingrese 1 para SI o 0 para NO)";
            cin >> tGuests[i].attendance;
        }
    }
}

void deleteGuest(guests& tGuests, int tDNI, int invitations)
{
    
        for (int i = 1; i < invitations; i++)
    {
        if (tDNI == tGuests[i].dni)
        {
            for (int j = i; j < invitations; j++)
            {
                tGuests[j].guestName = tGuests[j + 1].guestName;
                tGuests[j].dni = tGuests[j + 1].dni;
                tGuests[j].attendance = tGuests[j + 1].attendance;
            }
            break;
        }
    }

}

void listGuests(guests& tGuests, int invitations)
{
    
    cout << "Lista de invitados: " << endl;
    for (int i = 1; i < invitations; i++)
    {
        cout << "Nombre: " << tGuests[i].guestName << endl;
        cout << "DNI: " << tGuests[i].dni << endl;
        cout << "Invitacion: " << tGuests[i].ticketNumber << endl;
        if (tGuests[i].attendance == true)
        {
            cout << "Asistencia confirmada." << endl;
    
        } else {
            cout << "Aun no ha confirmado su asistencia." << endl;
        }
        
    }
}

void isComing(guests& tGuests, int tDNI, int invitations)
{
    
    for (int i = 1; i < invitations; i++)
    {
        if (tDNI == tGuests[i].dni)
        {
            if (tGuests[i].attendance == true)
            {
                cout << "El invitado ha confirmado su asistencia";
            }
            else
            {
                cout << "El invitado aun no ha confirmado su asistencia";
            }
            break;
        }
    }
}

void editAttendance(guests& tGuests, int tDNI, int invitations)
{
    
     for (int i = 1; i < invitations; i++)
    {
        if (tDNI == tGuests[i].dni)
        {
            tGuests[i].attendance = !tGuests[i].attendance;
            break;
        }
    }
}

void save(guests& tGuests, int invitations){
    
    ofstream file;
    file.open("guestList.csv");
    for (int i = 1; i < invitations; i++)
    {
        file << tGuests[i].guestName << "," << tGuests[i].dni << "," << tGuests[i].ticketNumber <<
         "," << tGuests[i].attendance << endl;
    }
    
    file.close();
}
