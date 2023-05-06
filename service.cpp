#include "service.h"

Service::Service(TranzactieRepository &handleRepo) : handleRepo(handleRepo)
{
}

Tranzactie Service::createTransaction()
{
    string description;
    string type;
    int sum;
    int day;
    cout << "Insert Description: " << endl;
    cin >> description;
    cout << "Insert Type: " << endl;
    cin >> type;
    cout << "Insert Sum: " << endl;
    cin >> sum;
    cout << "Insert Day: " << endl;
    cin >> day;

    Tranzactie newTransaction(sum, day, description, type);
    return newTransaction;
}

void Service::readTransactions()
{
    handleRepo.showTranzactii();
}

void Service::ModifyTranzaction(int id)
{
    int x;
    cin >> x;
    if (x == 1)
    {
        try
        {
            Tranzactie aux = handleRepo.findTransactionById(id);
            string type;
            cout << "What's the new type? " << endl;
            cin >> type;
            aux.setType(type);

            handleRepo.deleteTranzactie(id);
            handleRepo.addTranzactie(aux);
        }
        catch (const char *msg)
        {
            cerr << msg << endl;
        }
    }
    else if (x == 2)
    {
        try
        {
            Tranzactie aux = handleRepo.findTransactionById(id);
            string type;
            cout << "What's the new type? " << endl;
            string description;
            cin >> description;
            aux.setDescriere(description);

            handleRepo.deleteTranzactie(id);
            handleRepo.addTranzactie(aux);
        }
        catch (const char *msg)
        {
            cerr << msg << endl;
        }
    }
    else if (x == 3)
    {
        try
        {
            Tranzactie aux = handleRepo.findTransactionById(id);
            string type;
            cout << "What's the new type? " << endl;
            int sum;
            cin >> sum;
            aux.setSuma(sum);

            handleRepo.deleteTranzactie(id);
            handleRepo.addTranzactie(aux);
        }
        catch (const char *msg)
        {
            cerr << msg << endl;
        }
    }
    else if (x == 4)
    {
    }
}
void Service::deleteTransaction()
{
    int id;
    cout << "Choose the ID of transaction" << endl;
    cin >> id;

    handleRepo.deleteTranzactie(id);
}

stack<Tranzactie> Service::FilterTranzactions(string filter, string type)
{
    stack<Tranzactie> filteredStack;
    stack<Tranzactie> auxStack = handleRepo.getStack();
    while (!auxStack.empty())
    {
        if (filter == "type")
        {
            if (auxStack.top().getType() == type)
            {
                filteredStack.push(auxStack.top());
            }
        }
        else if (filter == "description")
        {
            if (auxStack.top().getDescriere() == type)
            {
                filteredStack.push(auxStack.top());
            }
        }
        auxStack.pop();
    }
    return filteredStack;
}
int Service::SumOfType(string type)
{
    stack<Tranzactie> auxStack = handleRepo.getStack();
    int sum = 0;
    while (!auxStack.empty())
    {
        if (auxStack.top().getType() == type)
        {
            sum = sum + auxStack.top().getSuma();
        }
        auxStack.pop();
    }
    return sum;
}

void Service::Undo()
{
    handleRepo.setStack(handleRepo.getUndoStack());
}