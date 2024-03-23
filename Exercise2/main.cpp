#include <iomanip>
#include <iostream>
#include <fstream>

// costruisco funzione che trasli e riscali l'intervallo [1,5] nell'intervallo [-1,2]
double cambioValore (double val)
{
    val = (val - 1) * (3.0/4.0) - 1; // length[1,5] = 4.0 e length[-1,2] = 3.0
    return val;
}


int main()
{
    // apro il file di lettura dei dati e controllo la sua esistenza
    std::string nomeFile = "data.csv";
    std::ifstream ifstr(nomeFile);
    if (ifstr.fail())
    {
        std::cerr << "Il file " << nomeFile<< " non esiste" << std::endl;
        return 1; // se fallisce, mi da un numero diverso da zero come exit-code
    }

    // inizializzo le variabili
    double valore;
    double somma = 0;
    unsigned int contatore = 0;
    double media = 0;

    // creo un file di output dove poter salvare gli output, sempre verificando che ciò sia possibile
    std::ofstream fileOutput("result.csv");
    if (fileOutput.fail())
    {
        std::cerr <<"Non è stato possibile creare un file di output" << std::endl;
    }

    // intestazione del file
    fileOutput << "# N mean" << "\n";

    // ciclo che mi permettere di calcolare la media, calcolando i valori sul nuovo intervallo
    while(ifstr >> valore)
    {
        valore = cambioValore(valore);
        somma += valore;
        contatore++;
        media = somma / contatore;
        fileOutput << contatore << " " << std::scientific << std::setprecision(16) << media << "\n";
    }

    // chiusura dei file
    ifstr.close();
    fileOutput.close();

    return 0;
}
