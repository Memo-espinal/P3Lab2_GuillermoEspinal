#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int mcd (int numero , int mod){
	if (mod == 0){
		return numero;
	}else{
		return mcd(mod, numero%mod);
	}
}

int Funcion_Euler(int numero){
	int contador_euler;
	for (int i=1 ; i<numero ;i++){
		if (mcd(numero,i)==1){
			contador_euler++;
		}
	}
	return contador_euler;
	
}
int juego_arreglos(int tama ){
	int array[tama];
	for (int i =0;i<tama;i++){
		array[i]=-50+rand()%(-50+150);
	}
	int t_jugador1,t_jugador2;
		t_jugador1=0;
		t_jugador2=0;
	int opcion;
	for (int i=0;i<tama/2;i++){
		
		cout<< "Jugador 1 eliga una posicion : " ;
		cin >>opcion;
		while (opcion > tama ||opcion <0||array[opcion]==-100){
			cout<< "Esa posicion ya fue usada o no esta entre el tamano del arreglo vuelva a ingresarla: ";
			cin>>opcion;
		}
		t_jugador1+=array[opcion];
		cout<< "Jugador 1 obtuvo: "<<array[opcion]<<endl;
		cout<<endl;
		array[opcion]=-100;
		
		//ahora jugador 2
			cout<< "Jugador 2 eliga una posicion : " ;
		cin >>opcion;
		while (opcion > tama ||opcion <0||array[opcion]==-100){
			cout<< "Esa posicion ya fue usada o no esta entre el tamano del arreglo vuelva a ingresarla: ";
			cin>>opcion;
		}
		t_jugador2+=array[opcion];
		cout<< "Jugador 2 obtuvo: "<<array[opcion]<<endl;
		cout<<endl;
		array[opcion]=-100;
		
		if (i ==tama-1){
			cout<<"FINAL - [PTS J1: "<<t_jugador1<<"<-->"<<"PTS J2: "<<t_jugador2<<"]"<< endl;
			
		}else {
			cout<<"Ronda "<<i<<" - [PTS J1: "<<t_jugador1<<"<-->"<<"PTS J2: "<<t_jugador2<<"]"<< endl;
		}
		
	}
	if (t_jugador1>t_jugador2){
		return 1;
	}else if (t_jugador1<t_jugador2 ) {
		return 2;
	}else {
		return 3;
	}
/*	for (int i =0;i<tama;i++){
		cout<< array[i]<<" ";
	}
	cout<< endl;
*/	
	
	return 1;
}

void Pascal(int tamano){
	int array1[tamano];
	int array2[tamano];
	int numero ;
	
	
	for(int i =0;i<tamano;i++){
		//array1[0]=1;
	
		
		numero =1;
		for(int j=0 ;j<=i ;j++){
			//cout<< array1[0]<<" ";
			//array1[0]*=(i-j)/j;  
			cout<< numero <<" ";
			//numero*=(numero-j)/j;
			int resta =numero-(j+1);
			//cout<< "aqui llegue";
			int multiplicacion =resta/(j+1);
			//cout<< "aqui llegue";
			numero *=multiplicacion;//numero;
			//cout<< "aqui llegue";
     
			
		/*	if (j==0&&i==0){
				//int array1[tamano];
				for(int x=0;x<tamano;x++){
					if(x=0){
						array1[x]=1;
					}
				}
				for(int x=0;x<tamano;x++){
					cout<< array1[x]<<" ";
				}
			}
			
			if (i==1){
				for 
			}
			
		}*/
		}
	cout<< endl;
	}
}

int main (){
	srand(time (NULL));
	
	int eleccion=1;
	 
	 while(eleccion >-1 && eleccion !=0){
	 	cout << "1.- Funcion de Euler " <<endl
	 		 <<	"2.- Triangulo de Pascal "<<endl
	 	 	 << "3.- Juego de Arreglos "<<endl ;
	 	 	 
	 	cin >> eleccion;
	 	
	 	switch (eleccion){
	 		case 1: 
	 		int numero ;
	 		 cout<<"Ingrese 1 numero: ";
			 cin >> numero ;
			 
			 cout << "Su MCD es igual a : "<< Funcion_Euler(numero)<< endl;
			 
			 break;
			  
			  
	 		case 2:  
	 			int tamano_triangulo;
	 			cout<< "Ingrese el tamano del triangulo: ";
	 			cin >> tamano_triangulo;
	 			Pascal(tamano_triangulo);
	 			break;
	 			
	 			
	 		case 3:
			 int tama; 
			 cout<<"Ingrese el tamano del arreglo : "<<endl;
			 cin >> tama;
			 while (tama%2!=0){
			 	cout<< "El tamano debe de ser par! vuelva lo a ingresar: ";
			 	cin >>tama;
			 }
			 int x= juego_arreglos(tama);
			 if(x==1){
			 	cout<< "J1 GANA!"<<endl;
			 }else if (x==2){
			 	cout<<"J2 GANA!"<<endl;
			 	
			 }else {
			 	cout<<"EMPATE!"<<endl;
			 }
	 			break;
	 	
		 
		 }
		 
	 }
	 cout << "Fin";
	 
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
