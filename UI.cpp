#include "service.cpp"

void ModifyTransactionUI()
{
    cout << "-----------------------------------------" << endl;
    cout << "Choose what to modify: " << endl;
    cout << endl;
    cout << "1. Type" << endl;
    cout << "2. Description" << endl;
    cout << "3. Sum" << endl;
    cout << "4. Go Back" << endl;
    cout << "-----------------------------------------" << endl;
}
void mainUI()
{
    cout << "-----------------------------------------" << endl;
    cout << "Choose an option: " << endl;
    cout << endl;
    cout << "1. Add Transaction" << endl;
    cout << "2. Modify Transaction" << endl;
    cout << "3. Show Transactions" << endl;
    cout << "4. Delete Transaction" << endl;
    cout << "5. Filter Transactions" << endl;
    cout << "6. Sum of Type" << endl;
    cout << "7. Reset All" << endl;
    cout << "8. Close Console" << endl;
    cout << "-----------------------------------------" << endl;
}

void mainUILogic(TranzactieRepository tranzactie)
{
    mainUI();
    Service service(tranzactie);
    int x;
    cin >> x;
    if (x == 1)
    {
        tranzactie.addTranzactie(service.createTransaction());
        mainUILogic(tranzactie);
    }
    else if (x == 2)
    {
        int id;
        cout << "Choose the ID of the transaction:" << endl;
        cin >> id;
        ModifyTransactionUI();
        service.ModifyTranzaction(id);
        mainUILogic(tranzactie);
    }
    else if (x == 3)
    {
        service.readTransactions();
        mainUILogic(tranzactie);
    }
    else if (x == 4)
    {
        service.deleteTransaction();
        mainUILogic(tranzactie);
    }
    else if (x == 5)
    {
        string filter;
        string value;
        cout << "Filtered by (type, description): " << endl;
        cin >> filter;
        cout << "Value of filter: " << endl;
        cin >> value;
        TranzactieRepository filteredRepo(service.FilterTranzactions(filter, value));
        filteredRepo.showTranzactii();
        mainUILogic(tranzactie);
    }
    else if (x == 6)
    {
        string type;
        cout << "Choose the type (in, out): " << endl;
        cin >> type;
        cout << "The sum is equal to: " << service.SumOfType(type) << endl;
        mainUILogic(tranzactie);
    }
    else if (x == 7)
    {
        service.Undo();
        mainUILogic(tranzactie);
    }
    else if (x == 8)
    {
        cout << "Console closed" << endl;
    }
}