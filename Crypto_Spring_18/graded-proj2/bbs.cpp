#include "bbs.h"
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>

void bbs::test()
{
    /*This tests your code.  Incorrect functions will produce assertion failures, stopping the program.*/
    cout << "Beggining test.. look out for assertion failure...that means something doesn't work." << endl;
    k.p = mpz_class("393364468015148770723118656477560183713355681480094572238494407330843450960583722335395238199792607956457774203690429141970553820850007570623836353604656348296275721814679013721709042642815183753148273595655083779285712271090667496681267946805768189485168951358553794904925808374976198236166993297599");
    k.q= mpz_class("19730782958738001503594163903248305852033210033516056812244511400194579120758116276265078572627768263280636023942659611833160010284399383980511125510276087197563676480034830310158633169443033496981866227929605137971650219400678832088273244925607080140451171076918368252226931951569309173451339");
    k.M= mpz_class("7761388942086337020074057111116638903687199763346127789613544711500333036647345529070070339703312265286817989460023387222683121312694413361735890609960435379902732197589400662432999231312251977583464563320546797917442439458581104409242784764133570944428070092057501254115604660713288069382951175437516189229374977541242299344454874690482938125735363147996890227940681421563783095298459732550108470479359257883529079428099292631500092316190026837307895512651484831444111968429593584461052000921649413963108910079466027199811957514479150002665908776715418936540326716445736665515004163572035061");
     k.x = mpz_class("31776943112721570169191361263612573087385467074289961762596304660807811537083761060058907168559934273129598636703199203301160083292082461530307768956468407108903509335165051362441805098325399095245644286276590741067692263205599264117026200589395723594043721845413787610901250893796386395651074309812");
    x=k.x;
    assert(k.p*k.q == k.M);

    cout << "Testing next_state():\n";
    next_state();
    mpz_class x_1 = mpz_class("1889445826213994265889069884236283754895419255034939672368210035591392754294964041244757095905958050931183601933092215239269196334867506132691405213268100705816384639286734366689582250851176957355083268003333608725557995805981346082128549761818803743685462790287945246743843168115922170289420210415443210279587850039737170452980833898282274576588734941089478886294405372685673853849170477321418704199881068173321758300838469065984804098073414642591538159597673121485436128651523359088749258709265083045238169758282509446754363136719191432315256665267118639839609933562935648300688123253969122");
    assert(x_1==x);
    //cout << x << endl;
    next_state();
    mpz_class x_2 = mpz_class("6285931399181034740208148225036256711232477260467191637063400130533672765418538367765830729987521316203487193845102979413171002594842779770980031568938623952678339999445744631472008175266535107746971263271230869116783156197673587747091470094773047775137072687481225155582089645855850968114329561961220823631074871069265795282963079938508149356031990200067612114220306863474092359274138513245588028567990119543738860170895644099198487425459201550848562144452177393850078052937725613360837797070338303181859591126315163378099952374916219713364417177990228754492572862971262978394165650172536411");
    assert(x_2 == x);

    cout << "next_state() passed." << endl;
    cout << "Testing get_stream_byte():" << endl;
    unsigned char c = get_stream_byte();
    unsigned char d = get_stream_byte();
    assert( 113==(unsigned int) c);
    assert( 30== (unsigned int) d);
    cout << "get_stream_byte() passed." << endl;
    cout << "Testing encrypt_byte():" << endl;
    assert(196==encrypt_byte(50));
    assert(168==encrypt_byte(200));
    cout << "encrypt_byte() passed." << endl;
    cout << "Testing encrypt_buffer() for encryption:" << endl;
    char buffer[] = "roses are red, violets are blue";
    char bufcrypt[] = {-76,22,-85,-26,-50,-4,92,44,-103,28,91,-116,-51,84,-64,109,92,-90,-38,37,-31,-14,125,91,-43,104,-38,88,-47,-69,-58};

    int len = strlen(buffer);
    encrypt_buffer(buffer,len,k.x);
    for (int i = 0; i < len;i++)
    {
        assert(buffer[i]==bufcrypt[i]);
    }
    cout << "encrypt_buffer() passed." << endl;
    cout << "Testing encrypt_buffer() for decryption:" << endl;;
    char buffer2[] = "roses are red, violets are blue";
    encrypt_buffer(buffer,len,k.x); //In a stream cipher decryption = encryption.
    for (int i = 0; i < len;i++)
    {
        assert(buffer[i]==buffer2[i]);
    }
    cout << "encrypt_buffer() passed." << endl;
}

void bbs::encrypt_buffer(char* s,int len, mpz_class x_0)
{
    /*This function calls encrypt_byte().  It replaces every byte of s with
      the ciphertext that results from using Blum Blum Shub as a stream cipher.
      The state x is set to be x_0, which will probably be the initial state k.x*/
    x = x_0;
    for(int i = 0; i < len;i++)
    {
       *s = encrypt_byte(*s);
        s++;
    }
}

unsigned char bbs::encrypt_byte(unsigned char c)
{
    /*This function calles get_stream_byte() to retrieve a byte of pseudo-random data.
      It returns the XOR of c and the byte of stream data.
      The effect is to encrypt the single byte c.*/
    unsigned char a = get_stream_byte();
    return c^a;
}

void bbs::key_gen()
{
    k.p = get_prime();
    k.q = get_prime();
    k.M = k.p*k.q;
    get_seed_x();

}

bbs::bbs(int num_security_bits)
{
    /*Constructor.  Set security level, generate parameters p,q, M, and x_0 .*/
    assert(num_security_bits%8==0);  //bits should divide evenly into bytes
    num_bits = num_security_bits;
    key_gen();
    x=k.x;
    cout << "p = " << k.p << "\nq= " << k.q << "\nM= " << k.M << "\n x_0 = " << x << endl;

}

unsigned char bbs::get_stream_byte()
{
    /*This function gets a byte of stream data. To produce one bit of stream data, next_state() is called and then
      a stream bit results from taking the current state mod 2.  This is "bit" in the code below.  Doing this 8 types
      yields a byte of stream data.  In the missing part of the code you should insert the bit into the correct place
      in the byte c.  Think of c as 8 bits.  Use the shift operator and the | operator to insert bit into the correct place. */
    unsigned char c = 0; //00000000
    for(int i = 0;i < 8;i++)
    {
        next_state();
        mpz_class A = x%2;
        unsigned char bit = (unsigned char) A.get_ui();
        c |= (bit<<i); // THIS WORKS YAYYY!!!
    }
    return c;
}

void bbs::next_state()
{
    /*This updates Blum Blum Shub to the next state. If x is the current state then the
      next state is simply x squared (mod M).
    /**FILL ME IN**/
    x = (x*x)%k.M;


}

void bbs::get_seed_x()
{
    /*This picks the initial state k.x using a cryptographically secure
      random number generator. Wikipedia says:
      The seed x should be an integer that is co-prime to M (i.e. p and q are not factors of x) and not 1 or 0.
*/
    k.x = 0;
    while ((k.x==0) || (k.x==1) || (k.x%k.p==0) || (k.x%k.q==0))
        k.x=mpz_class(get_entropy(num_bits/8),16);

}

mpz_class bbs::get_prime()
{
/*This function returns a large prime, roughly "num_bits" long.
  The prime is chosen at random using random data from /dev/urandom.
  We ensure that the resulting prime is congruent to 3 mod 4, because this
  assumption makes Blum Blum Schub more secure.*/

    mpz_class rop;
    while(1)
    {
        string num = get_entropy(num_bits/8);
        mpz_class C(num,16);
        if ((C%4) != 3)
            continue;
        int is_prime = mpz_probab_prime_p(C.get_mpz_t(),25);
        if (is_prime) {
            rop=C;
            break;
        }
    }
    return rop;
}


string bbs::get_entropy(int num_bytes)
{
    /*INput:  the number of bytes of entropy requested
    /*Output: A string representing a random number num_bytes long in hex format
    /*Description: This function returns a random integer of specified length (in bytes) as a hex string.
        It must produce the random integer by reading from the device TRNG.
        Warning: may not work on Windows.
    */
    FILE* urnd = fopen("/dev/urandom","r");
    if(!urnd){
        cout << "Uh oh, /dev/urandom did not open.  Using Windows?  Try cocalc." << endl;
        assert(urnd);
    }
    int bytes_read = 0;


    stringstream ss;
    while(bytes_read < num_bytes)
    {
        int c = getc(urnd);
       // printf("%d %hhx\n",bytes_read,c);
        ss << std::hex << (int)c;
        bytes_read += 1;
    }
   // cout << "bytes_read= " << bytes_read << "num_bytes = " << num_bytes << endl;
    string value = ss.str();
    return value;
}


int main()
{

    bbs B(1024);
    B.test();
}