## Prova Finale del corso di Algoritmi e Principi per l'Informatica - Politecnico di Milano (2021)
Progetto di "Algoritmi e Strutture Dati" del corso "PROVA FINALE (PROGETTO DI ALGORITMI E STRUTTURE DATI)", Politecnico di Milano (2021). Voto ottenuto: 30 e Lode.

### Obiettivo
- L'obiettivo del progetto è la gestione di una classifica tra grafi diretti pesati. La classifica tiene traccia dei `k` "migliori" grafi.
- Il programma da realizzare riceve in ingresso:
    - Due parametri, una sola volta (sulla prima riga del file, separati da spazio): `d` - il numero di nodi dei grafi, `k` - la lunghezza della classifica.
    - Una sequenza di comandi tra `AggiungiGrafo [matrice di adiacenza]`, `TopK`.
  
        - `AggiungiGrafo [matrice di adiacenza]` richiede di aggiungere un grafo a quelli considerati per stilare la classifica. È seguito dalla matrice di adiacenza del grafo stesso, stampata una riga per ogni rigo, con gli elementi separati da virgole.
        - `TopK` richiede al programma di stampare gli indici interi dei `k` grafi aventi i `k` valori più piccoli della seguente metrica: somma dei cammini più brevi tra il nodo 0 e tutti gli altri nodi del grafo.

### Realizzazione
- Linguaggio di programmazione: C
- Libreria standard C
- No multithreading
- Ingresso stdin, risultati stdout

### Valutazione
La correttezza e l'efficienza della soluzione proposta sono valutate con batterie di test automatizzate. Il sistema di verifica calcola il tempo macchina e la memoria utilizzati.

Ulteriori dettagli ed esempi sono forniti `Consegna.pdf`.
