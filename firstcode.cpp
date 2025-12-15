
1.

int fun(int n) 
{
    int count = 0 ;
    for (int i = n; i > 0; i /= 2) // O(log n) kez çalışır
        for (int j = 0; j < i; j++) // i kez çalışır
            count += 1;
    return count ;

}        //  O(N)



2.


int a = 0, b = 0 ;

for (i = 0; i < N; i++) { // O(N) kez çalışır
    a = a + rand();
}
for (j = 0; j < M; j++) { // O(M) kez çalışır
    b = b + rand();
} //  O(N + M)


3.
for ( int i = N ; i > 0 ; i = i/2) /* O(log N) */
 { for (int j = 1; j < N; j = j * 2)  // O(log N) kez çalışır
      {  for (int k = 0; k < N; k = k + 2)  // O(N/2) = O(N) kez çalışır
             }
    } // O(N (log N)^2)


4.
    for (int i = 0; i < N; i++) { // O(N) kez çalışır
    i * = k;
}  // O(\log N)


5.
    int i , j, k = 0 ;
    for (i = N / 2; i < N; i++){  // N/2 kez çalışır -> O(N)
        for (j = 2; j < N; j = j * 2) { // O(log N) kez çalışır
        k = k + N / 2;
    }
} // O(N * log N)


6.

int a = 0 , i = N ;    
while (i > 0) {
    a += i;
    i /= 2;
} // O(\log N)


7. 

int value = 0;
for (int i = 0; i < N; i++) { // O(N) kez çalışır
    for (int j = 0; j < i; j++) { // i kez çalışır
        value += 1;
    }
} // O(N^2)