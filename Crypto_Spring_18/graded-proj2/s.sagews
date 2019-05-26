︠9c25bcf3-aa83-4d5a-96e8-bb6f19278742s︠
import os
rawseed = os.urandom(32)
convert_to_int = lambda array: int("".join(array).encode("hex"), 16)
intseed = convert_to_int(rawseed)
intseed = 0
set_random_seed(intseed)
p=random_prime(2**32)
q=random_prime(2**32)
while p%4 !=3 or q%4 != 3:
    print p%4,q%4
    p=random_prime(4*10**9)
    q=random_prime(4*10**9)
︡159277e6-a152-450e-977a-0cddc31a44ae︡{"stdout":"3 1\n1 3\n1 3\n3 1\n1 3\n"}︡{"done":true}︡
︠7e2a4ad7-482f-4e36-81d3-1e2dc523fe1fs︠
p%4,q%4
︡f7a020f2-ed0c-40ca-a5f5-3a7da942d7dc︡{"stdout":"(3, 3)\n"}︡{"done":true}︡
︠afad02cd-9587-4d14-b414-e09cf44168efs︠
p,q
︡a365be1e-9d2f-419d-8ff8-a82d50a001ea︡{"stdout":"(1002501779, 2136277427)\n"}︡{"done":true}︡
︠84b8bfef-46b4-41d6-8cd9-47ea7638ff2ds︠
random_prime?
︡49adcbfa-0aa6-46c3-a18a-144319941968︡{"code":{"filename":null,"lineno":-1,"mode":"text/x-rst","source":"File: /ext/sage/sage-8.1/local/lib/python2.7/site-packages/sage/arith/misc.py\nSignature : random_prime(n, proof=None, lbound=2)\nDocstring :\nReturns a random prime p between lbound and n (i.e. lbound <= p <=\nn). The returned prime is chosen uniformly at random from the set\nof prime numbers less than or equal to n.\n\nINPUT:\n\n* \"n\" - an integer >= 2.\n\n* \"proof\" - bool or None (default: None) If False, the function\n  uses a pseudo-primality test, which is much faster for really big\n  numbers but does not provide a proof of primality. If None, uses\n  the global default (see \"sage.structure.proof.proof\")\n\n* \"lbound\" - an integer >= 2 lower bound for the chosen primes\n\nEXAMPLES:\n\n   sage: random_prime(100000)\n   88237\n   sage: random_prime(2)\n   2\n\nHere we generate a random prime between 100 and 200:\n\n   sage: random_prime(200, lbound=100)\n   149\n\nIf all we care about is finding a pseudo prime, then we can pass in\n\"proof=False\"\n\n   sage: random_prime(200, proof=False, lbound=100)\n   149\n\nAUTHORS:\n\n* Jon Hanke (2006-08-08): with standard Stein cleanup\n\n* Jonathan Bober (2007-03-17)"}}︡{"done":true}︡
︠f9ba2301-0a85-469c-8c06-c9dca05742da︠

︡92e0bc48-cdec-458d-825d-c44624f8e3db︡
︠f808fedf-8ae3-4db9-a9c3-d75b24aa70efs︠

is_prime(9930452184901027954805287022392632953161607207300736983059851378529970171)
︡2cab370a-b01a-453c-8a29-54d68c3f2075︡{"stdout":"True\n"}︡{"done":true}︡
︠d2bf22b2-39f5-44ad-90cd-823f25a37a08s︠
9930452184901027954805287022392632953161607207300736983059851378529970171%4
︡a962aca0-6d68-4bc1-abda-c39aa547b834︡{"stdout":"3\n"}︡{"done":true}︡
︠e5cb146b-1b1d-4f35-9192-a6a571be056fs︠
p = 393364468015148770723118656477560183713355681480094572238494407330843450960583722335395238199792607956457774203690429141970553820850007570623836353604656348296275721814679013721709042642815183753148273595655083779285712271090667496681267946805768189485168951358553794904925808374976198236166993297599
q= 19730782958738001503594163903248305852033210033516056812244511400194579120758116276265078572627768263280636023942659611833160010284399383980511125510276087197563676480034830310158633169443033496981866227929605137971650219400678832088273244925607080140451171076918368252226931951569309173451339
M= 7761388942086337020074057111116638903687199763346127789613544711500333036647345529070070339703312265286817989460023387222683121312694413361735890609960435379902732197589400662432999231312251977583464563320546797917442439458581104409242784764133570944428070092057501254115604660713288069382951175437516189229374977541242299344454874690482938125735363147996890227940681421563783095298459732550108470479359257883529079428099292631500092316190026837307895512651484831444111968429593584461052000921649413963108910079466027199811957514479150002665908776715418936540326716445736665515004163572035061
x_0 = 31776943112721570169191361263612573087385467074289961762596304660807811537083761060058907168559934273129598636703199203301160083292082461530307768956468407108903509335165051362441805098325399095245644286276590741067692263205599264117026200589395723594043721845413787610901250893796386395651074309812
x_0
︡1347d062-ab9d-40f7-a642-02756c25d985︡{"stdout":"31776943112721570169191361263612573087385467074289961762596304660807811537083761060058907168559934273129598636703199203301160083292082461530307768956468407108903509335165051362441805098325399095245644286276590741067692263205599264117026200589395723594043721845413787610901250893796386395651074309812\n"}︡{"done":true}︡
︠a0d47151-029f-4c21-83d5-3058fc36d5a8s︠
x_1 = 1889445826213994265889069884236283754895419255034939672368210035591392754294964041244757095905958050931183601933092215239269196334867506132691405213268100705816384639286734366689582250851176957355083268003333608725557995805981346082128549761818803743685462790287945246743843168115922170289420210415443210279587850039737170452980833898282274576588734941089478886294405372685673853849170477321418704199881068173321758300838469065984804098073414642591538159597673121485436128651523359088749258709265083045238169758282509446754363136719191432315256665267118639839609933562935648300688123253969122
x_1 == (x_0**2)%M
︡70706b0f-811e-49d5-9eb7-4d436dae6323︡{"stdout":"True\n"}︡{"done":true}︡
︠8dfead95-7ed0-4aa6-b006-16c4a38740bcs︠
x_2 = 6285931399181034740208148225036256711232477260467191637063400130533672765418538367765830729987521316203487193845102979413171002594842779770980031568938623952678339999445744631472008175266535107746971263271230869116783156197673587747091470094773047775137072687481225155582089645855850968114329561961220823631074871069265795282963079938508149356031990200067612114220306863474092359274138513245588028567990119543738860170895644099198487425459201550848562144452177393850078052937725613360837797070338303181859591126315163378099952374916219713364417177990228754492572862971262978394165650172536411

x_2 == (x_1**2)%M
︡8137f816-4f3d-445a-8e3c-0239907cc633︡{"stdout":"True\n"}︡{"done":true}︡
︠9c3200bd-ff1e-4839-9452-3dc0dd5a99aas︠

is_prime(19730782958738001503594163903248305852033210033516056812244511400194579120758116276265078572627768263280636023942659611833160010284399383980511125510276087197563676480034830310158633169443033496981866227929605137971650219400678832088273244925607080140451171076918368252226931951569309173451339)
︡cbb908d9-6bdd-49c9-b523-9edc1b044d90︡{"stdout":"True"}︡{"stdout":"\n"}︡{"done":true}︡
︠a4a5bf8f-78d1-4721-afcd-ba6ceeb930f1︠










