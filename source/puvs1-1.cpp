# include <stdio.h>     // Standard Bibliothek stdio wird inkludiert
# include <omp.h>       // Open Multi-Processing wird inkludiert 
/*
Authors:
Falko Horn 122435
Mathis K�nzel 122979
Elisabeth ALice Rahn 122592
*/
int main(int argc, char* argv[])
{
    int numThreads;     // Integer numThreads wird deklariert 
    int threadID;       // Integer threadID wird deklariert
    double start, end;   // Double start & end wird deklariert 

    start = omp_get_wtime();    // setzt start auf den aktuellen zeitwert

    /*  parallelisierung wird gestartet  */
#pragma omp parallel num_threads(8)
    {
        threadID = omp_get_thread_num();                //Nummer vom aktuellen Thread wird in ThreadID gespeichert
        printf("Hello from thread %d\n", threadID);

        /* If-Klausel -> Ausgabe der ANzahl aller Threads     */
        if (threadID == 0)
        {
            numThreads = omp_get_num_threads();         //Anzahl der Threads wird in numThreads gespeichert 
            printf("Number of threads: %d\n", numThreads);
        }
    }
    end = omp_get_wtime();                              //setzt end auf den aktuellen Zeitwert
    printf("This task took %f seconds\n", end - start); //Berechnung der vergangenen Zeit

    return 0;
}

/*
Wir haben das Programm mit 1,2,4,8 und 16 Threads gestartet.
Jeweils wurde die Anzahl der Ausgaben erh�ht.

Vermutung:
Es ist zu erwarten dass mehr Threads l�nger brauchen, weil der Arbeitsaufwand proportional zu der Anzahl an Threads steigt.
Das bedeutet, dass pro Thread ein Satz parallel augegeben wird.
Zus�tzlich gibt es dann aber noch den Organisationsaufwand, der beim Zuweisen der Parallelisierung entsteht.

Durchf�hrung:
In einem beigef�gten Balkendiagramm haben wir die Berechnungszeit mit der Anzahl der Threads gegen�bergestellt.
In den meisten F�llen war die Berechnung mit mehr Threads langsamer.
Allerdings gab es auch zuf�llige schnellere Berechnungen (siehe 8 Threads Versuch 3)

Auswertung:
Bis auf einige wenige Ausnahmen hat sich die Vermutung best�tigt.
Es scheint dennoch Situationen zu geben, in denen das Programm deutlich schneller l�uft.
*/