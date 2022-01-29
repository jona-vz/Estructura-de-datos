//Listas dobles


/*
1.-Crear lista
	-Tener la struct de lista
		-primero
		-ultimo
		-longitud
	-crear lista
		-Reservar memoria con malloc
		-hacer NULL el primero
		-hacer NULL el ultimo
		-inicializar longitud en 0
		
3.-Menu
	-Dar opciones
	-Obtener que se quiere hacer
	
4.-Insertar
	-Crear Nodo
		-Reservar memoria para el nodo
		-crear siguiente y anterior
		-asignarle el dato a dato nodo->dato=dato,
		-poner NULL a siguiente
		-poner NULL a anterior
	-Insertar con lista vacia
		-el nuevo va a ser first y last
	-Insertar en lista con elementos
		-Insertar al inicio
			-nuevo en sig va a ser el primero ---nuevo->siguiente=lista->first
			-nuevo en anterior va a ser nulo----nuevo->anterior=NULL
			-anterior del que estaba en primero va a ser nuevo
			-actualizar first a nuevo----lista->first=nuevo
		-Insertar al final
			-el siguiente de last va a ser nuevo--lista->last->sig=nuevo
			-el anterior a nuevo va a ser last
			-el siguiente de nuevo va a ser null
			-actualizar last a nuevo
		-Insertar en medio
			-buscar la posicion-1
			-nuevo en siguiente va a ser el siguiente de la posicion
			-el de la posicion en siguiente va a ser nuevo
			-nuevo en anterios va a ser pos
			-nuevo-siguiente-anterior=nuevo
	-actualizar longitud
5.-Eliminar
	-Eliminar el primero
		-Nodo a eliminar se poner en first
		-first va a ser igual a first siguiente
		-first anterior va a ser null
		-destruir nodo
	-Eliminar el ultimo
		-nodo a eliminar se apunta a last
		-se actualiza las al anterior de last
		-siguiente de last es null
		-destruir nodo
	-Eliminar en medio
		-se busca el nodo 
		-apuntar al anterior del eliminado
		-siguiente del anterior es el siguiente del eliminado
		-anterior del siguiente es el anterior del eliminado
		-destruir nodo
	-actualizar longitud
6.-Imprimir
	-recorrer la lista
		-desde el primero se avanza buscando el null
	-imprimir de reversa

2.-Destruir la lista
	-vaciar toda la lista
		-destruir todos los nodos
			-nodo->sig=null
			-free nodo
	-destruir toda la lista
	
			




*/
