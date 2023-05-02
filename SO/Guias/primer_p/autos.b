MUTEX1 = [SEM(1), SEM(1)]
mutex2 = [SEM(1), SEM(1)]

autosCruzando[0,0]
var_compartida = 0
bloqueoLado = sem(1)
permisoPuente = sem(0)


auto(0)
	MUTEX1[0].WAIT
	if(var_compartida==0)
		bloqueLado.wait()
		bloqueoLado.signal()
	else
		bloqueoLado.wait
	
	autosCruzando[0]++
	MUTEX1[0].SIGNAL
	

	cruzar()
	
	mutex2[0].WAIT()
	autosCruzando[0]--
	if autosCruzando[0] == 0
		permisoPuente.signal()
	
	mutex2[0].signal()
	
auto(1)
	MUTEX[1].wait
	autoderecha++
	if(autoderecha==1)
		var_compartida = 1
	
	if(autosCruzandos[0] != 0)
		permisoPuente.wait()
	autosCruzando[1]++
	MUTEX[1].signal
	
	cruzar()
	
	mutex2[1].wait()
	autosCruzando[0]--
	if(autosCruzando[i] == 0)
		var_compartida = 0
		bloqueoLado.signal()
	mutex2[1].signal()
