## Project 5

### Public key cryptography

#### Due 5/1/18

In this project we will use the *openssl* command to generate and view public and private keys for the RSA algorithm as well as an elliptic curve.

This will be a hands-on project; I give a lot of examples of using `openssl` from the command line.

You can execute these commands from a `cocalc` terminal or from your own machine.  If you work on your own machine you may need to install `openssl` and `ssh` if they are not already installed.

##### What to submit:

Please write a short report on your findings using Markdown.  You can use this document as an example of a Markdown report.  Throughout this document look for italicized remarks that tell you exactly what to include in your submission.  They look like this:

_In the report you write for this project please include the birth name of the villian/anti-hero called Magneto._

#### RSA

These instructions are adaped from [here](https://en.wikibooks.org/wiki/Cryptography/Generate_a_keypair_using_OpenSSL).

```
$ openssl genpkey -algorithm RSA -out private_key.pem -pkeyopt rsa_keygen_bits:2048

```


This produces a 2048 bit RSA key and stores it in the file `private_key.pem`.

To view the result, you can open the file with a text editor, or do:

	$ cat private_key.pem

You should get something that looks like this:

	-----BEGIN PRIVATE KEY-----
	MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDCXs6C3hOWZZVL
	h6I6VMi55QCWxgulx1zkVDXMQ02ozctnUlLjwlUlrkjJf2nmRn3VCC1v7OV/mH76
	BN/1KPN7iV5aOOAw9maFcu0uyqfBIKzudQJbQ1IyLpa2Hp4C8NMLIPCHEhBNBljQ
	yozzYjkG/5yWICyzByzFfdNbIuPOXIvXHUxT5C1SGE16ypwff5m+GQeUN2KMN2Rq
	R2BiIGyE/+UoLq1kfeV7omWoBNS6SMNsMpwLybHmfROePWMMs7xM7gUbprk3H9Z6
	nY4oO8s164yjob9xcv1YEqRRkS3E24xuTmhNDFkNxQt8nyCj7/0sFXvzT2H28nhe
	wn0x7o1ZAgMBAAECggEAFHwfcaVsFQ6xtFsgGtuyp/zdmgZXVepz/NBvNw7k0WSX
	ClWfzMc/aBA9NZdLFuzY+Cm7eC9UZKUyxLDc1Z6yQpPQsNuLrT1awrfBDYxoL698
	6kjErc+jiwxj79+8MX0mEOcw0ltyAlwn4iFmx4PTlMw9uYi8jUW1Tz8almFP9wCU
	4muJMp03JG5NSXpzAnCs8TuZUdZL4UJ6/OPRK7F0qJdbANpr8ObUhi31QctM4+v6
	Uz4p893T+pDh00tC1JxIBUhTLRLQwwek9SdP30jg0aLCwgNyCv9qJjiw90E/uwxy
	GOltJzTiORW0GX7GlklycGx5ApgaXloimUZHkNT9jQKBgQDn5CdRLszYeSOOyHSR
	n2w8OPP4vr38DNMpzJ+s5TuyfJhepTgKO02pzP7t/4SnsQ5etkj8D1DgJIp7LVpU
	6yvJxvpa8tM4LUD62uTgp2H40UC+p0dRJ+fGx14DcUSeeQueaa/aPXvYOAcL/c4o
	85hHnz0dX9CLOSHcRRAcFHv+kwKBgQDWlAZXIb116+qQFBVPOIRb2wnoH4FEtjuP
	jW2oKhtPBxtM1R5EJ33ws5/RqI3dOraVz+BQjqjvGPqMuOYW/nbpYngKLVkpktft
	bAtdwcJIT7Rju2jrseYNGrNAB8Ob/33A+ONE1hO6/UFFdu0iDO1Fn0Tp0pLtxz9b
	vgrbT3aL4wKBgQDg1fdFIIJfNX1DeJqFgzSXY4Ux3gco9mpbcdoz8gMiuOmngrxG
	N1/Czk8zBXdifCp5rHYxZsw8t1FJwxx9j5NiTbn6KsyfAEmrsEcQh1pXvNPwxxI/
	3tg8hJtj7RPiL20TiFeH2+tTJme2ubyFOkKg1wWTkI4MHzX0c0X+Y+IhXwKBgQDG
	xUZ+TlX4N3sIzmHTCfKqOGSb7xtLMFhKKWPMJH05nsauTLmFvuOOJobEq5QGvE3I
	x1DurshU/FmUI++Ym05B8aJrIwj2Vv3JBI4e4s77N0JOJJwTwa7usq4bgVW1W139
	dVDqQjjyvYlKNNmD8l+VX+1xgEv1Ed5iONBLyfdxqwKBgB+O9mU+zglNL+IupA03
	/BGFjDXCHVsyId4IjIdhEed/mPa8hK75tDEU/Y6rMvmVjKZ+uVdyP0ju7lo9tZ0/
	CgUbuRu8rgyjHh8q/ugf5mVkaG9xmXxEST1Gi5pY1wSlPZ3HEVY0/R2XzBrySAko
	dRKMM8M2cZL/38rIPi0gYSbT
	-----END PRIVATE KEY-----

This is not super informative at first glance.  The key is encoded using a format called [base64](https://en.wikipedia.org/wiki/Base64).

_In the report that you write for this project, be sure to paste in your private key as I have done (just the openssl version)._

If you are a cryptocurrency fan it may look familiar, because cryptocurrency addresses are encoded using the related format [base58](https://en.wikipedia.org/wiki/Base58).

The purpose of base64 is to make arbitrary binary information printable in ASCII.  This allows binary info like cryptographic keys to be pasted into emails, web forms, configuration files, etc.  Base58 further allows binary information to be easily written out longhand, or dictated over the phone.

_In the report that you write for this project, please include the base64 encoding of the sentence "Salt lamps taste delicious." (google around for instructions)_

It is somewhat dangerous to store your private key in unencrypted form.  Often private key files are encrypted with a passphrase.  For instance, try this command:

	$ ssh-keygen

This will again generate an RSA private key but unlike `openssl` the `ssh` program will ask for a passphrase by default.  Your private key will be stored in encrypted form, and it will be unreadable without the passphrase.  This is good news if your computer is hacked.  To learn more about encrypting your private key using openssl see the _Encrypt a Private Key_ section in [this](https://www.digitalocean.com/community/tutorials/openssl-essentials-working-with-ssl-certificates-private-keys-and-csrs) tutorial.



In public key cryptography we want to be able to reveal our public information while keeping the private key private.  The next command will extract the public parts of your private key and store them in a separate file:

```
$ openssl rsa -pubout -in private_key.pem -out public_key.pem

```


For me, the resulting file `public_key.pem` is the following:

	-----BEGIN PUBLIC KEY-----
	MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwl7Ogt4TlmWVS4eiOlTI
	ueUAlsYLpcdc5FQ1zENNqM3LZ1JS48JVJa5IyX9p5kZ91Qgtb+zlf5h++gTf9Sjz
	e4leWjjgMPZmhXLtLsqnwSCs7nUCW0NSMi6Wth6eAvDTCyDwhxIQTQZY0MqM82I5
	Bv+cliAsswcsxX3TWyLjzlyL1x1MU+QtUhhNesqcH3+ZvhkHlDdijDdkakdgYiBs
	hP/lKC6tZH3le6JlqATUukjDbDKcC8mx5n0Tnj1jDLO8TO4FG6a5Nx/Wep2OKDvL
	NeuMo6G/cXL9WBKkUZEtxNuMbk5oTQxZDcULfJ8go+/9LBV7809h9vJ4XsJ9Me6N
	WQIDAQAB
	-----END PUBLIC KEY-----

_In the report that you write for this project, be sure to include your public key_.

This file is shorter than the private key, because it stores less information. You can see the contents of the file in unencoded form like this:

```
$ openssl rsa -text -pubin -in public_key.pem

```

Here is the resulting output:

	Public-Key: (2048 bit)
	Modulus:
		00:c2:5e:ce:82:de:13:96:65:95:4b:87:a2:3a:54:
		c8:b9:e5:00:96:c6:0b:a5:c7:5c:e4:54:35:cc:43:
		4d:a8:cd:cb:67:52:52:e3:c2:55:25:ae:48:c9:7f:
		69:e6:46:7d:d5:08:2d:6f:ec:e5:7f:98:7e:fa:04:
		df:f5:28:f3:7b:89:5e:5a:38:e0:30:f6:66:85:72:
		ed:2e:ca:a7:c1:20:ac:ee:75:02:5b:43:52:32:2e:
		96:b6:1e:9e:02:f0:d3:0b:20:f0:87:12:10:4d:06:
		58:d0:ca:8c:f3:62:39:06:ff:9c:96:20:2c:b3:07:
		2c:c5:7d:d3:5b:22:e3:ce:5c:8b:d7:1d:4c:53:e4:
		2d:52:18:4d:7a:ca:9c:1f:7f:99:be:19:07:94:37:
		62:8c:37:64:6a:47:60:62:20:6c:84:ff:e5:28:2e:
		ad:64:7d:e5:7b:a2:65:a8:04:d4:ba:48:c3:6c:32:
		9c:0b:c9:b1:e6:7d:13:9e:3d:63:0c:b3:bc:4c:ee:
		05:1b:a6:b9:37:1f:d6:7a:9d:8e:28:3b:cb:35:eb:
		8c:a3:a1:bf:71:72:fd:58:12:a4:51:91:2d:c4:db:
		8c:6e:4e:68:4d:0c:59:0d:c5:0b:7c:9f:20:a3:ef:
		fd:2c:15:7b:f3:4f:61:f6:f2:78:5e:c2:7d:31:ee:
		8d:59
	Exponent: 65537 (0x10001)
	writing RSA key
	-----BEGIN PUBLIC KEY-----
	MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwl7Ogt4TlmWVS4eiOlTI
	ueUAlsYLpcdc5FQ1zENNqM3LZ1JS48JVJa5IyX9p5kZ91Qgtb+zlf5h++gTf9Sjz
	e4leWjjgMPZmhXLtLsqnwSCs7nUCW0NSMi6Wth6eAvDTCyDwhxIQTQZY0MqM82I5
	Bv+cliAsswcsxX3TWyLjzlyL1x1MU+QtUhhNesqcH3+ZvhkHlDdijDdkakdgYiBs
	hP/lKC6tZH3le6JlqATUukjDbDKcC8mx5n0Tnj1jDLO8TO4FG6a5Nx/Wep2OKDvL
	NeuMo6G/cXL9WBKkUZEtxNuMbk5oTQxZDcULfJ8go+/9LBV7809h9vJ4XsJ9Me6N
	WQIDAQAB
	-----END PUBLIC KEY-----

You can see that this file contains the modulus (what we call $N$) and the public exponent $e$, which in this case is the constant 65537.  As you can see from the hex representation of $e = 0x10001$, the exponent is chosen to be small with small hamming weight so that $x^e\, \mod N$ can be quickly computed using the Square-and-Multiply algorithm. The value $N$ is given as a list of colon separated hex digits. Note that the modulus is $15\cdot 17 + 2$ bytes, which amounts to 2056 bits.  I think it is likely that all moduli begin with the 00 byte, giving precisely 2048 functional bits.

---

You can generate a very small modulus for fun (though you can't use this one in practice).  The smallest I was able to generate is 256 bits.

```
$ openssl genpkey -algorithm RSA -out private_key.pem -pkeyopt rsa_keygen_bits:256

...........+++++++++++++++++++++++++++

.......................................................+++++++++++++++++++++++++++

```

	$ openssl rsa -noout -modulus -in private_key.pem
	Modulus=A798A3B574226488185978AE3E9EC88AFEB88A5421DE672C197FE554D2469383



Why don't you try to use a Sage Worksheet on Cocalc to factor this modulus?  [This](http://doc.sagemath.org/html/en/thematic_tutorials/explicit_methods_in_number_theory/integer_factorization.html) document may be helpful.  For me it took about 11 minutes on Cocalc.  If it takes a lot longer you might want to try a different approach.

_In the report you submit, please include the factors of the above modulus._

---

We've seen a decoded version of our public key file.  Now let's look at a decoded version of the private key.

	$ openssl rsa -text -in private_key.pem

Here is the output:

	Private-Key: (2048 bit)
	modulus:
		00:c2:5e:ce:82:de:13:96:65:95:4b:87:a2:3a:54:
		c8:b9:e5:00:96:c6:0b:a5:c7:5c:e4:54:35:cc:43:
		4d:a8:cd:cb:67:52:52:e3:c2:55:25:ae:48:c9:7f:
		69:e6:46:7d:d5:08:2d:6f:ec:e5:7f:98:7e:fa:04:
		df:f5:28:f3:7b:89:5e:5a:38:e0:30:f6:66:85:72:
		ed:2e:ca:a7:c1:20:ac:ee:75:02:5b:43:52:32:2e:
		96:b6:1e:9e:02:f0:d3:0b:20:f0:87:12:10:4d:06:
		58:d0:ca:8c:f3:62:39:06:ff:9c:96:20:2c:b3:07:
		2c:c5:7d:d3:5b:22:e3:ce:5c:8b:d7:1d:4c:53:e4:
		2d:52:18:4d:7a:ca:9c:1f:7f:99:be:19:07:94:37:
		62:8c:37:64:6a:47:60:62:20:6c:84:ff:e5:28:2e:
		ad:64:7d:e5:7b:a2:65:a8:04:d4:ba:48:c3:6c:32:
		9c:0b:c9:b1:e6:7d:13:9e:3d:63:0c:b3:bc:4c:ee:
		05:1b:a6:b9:37:1f:d6:7a:9d:8e:28:3b:cb:35:eb:
		8c:a3:a1:bf:71:72:fd:58:12:a4:51:91:2d:c4:db:
		8c:6e:4e:68:4d:0c:59:0d:c5:0b:7c:9f:20:a3:ef:
		fd:2c:15:7b:f3:4f:61:f6:f2:78:5e:c2:7d:31:ee:
		8d:59
	publicExponent: 65537 (0x10001)
	privateExponent:
		14:7c:1f:71:a5:6c:15:0e:b1:b4:5b:20:1a:db:b2:
		a7:fc:dd:9a:06:57:55:ea:73:fc:d0:6f:37:0e:e4:
		d1:64:97:0a:55:9f:cc:c7:3f:68:10:3d:35:97:4b:
		16:ec:d8:f8:29:bb:78:2f:54:64:a5:32:c4:b0:dc:
		d5:9e:b2:42:93:d0:b0:db:8b:ad:3d:5a:c2:b7:c1:
		0d:8c:68:2f:af:7c:ea:48:c4:ad:cf:a3:8b:0c:63:
		ef:df:bc:31:7d:26:10:e7:30:d2:5b:72:02:5c:27:
		e2:21:66:c7:83:d3:94:cc:3d:b9:88:bc:8d:45:b5:
		4f:3f:1a:96:61:4f:f7:00:94:e2:6b:89:32:9d:37:
		24:6e:4d:49:7a:73:02:70:ac:f1:3b:99:51:d6:4b:
		e1:42:7a:fc:e3:d1:2b:b1:74:a8:97:5b:00:da:6b:
		f0:e6:d4:86:2d:f5:41:cb:4c:e3:eb:fa:53:3e:29:
		f3:dd:d3:fa:90:e1:d3:4b:42:d4:9c:48:05:48:53:
		2d:12:d0:c3:07:a4:f5:27:4f:df:48:e0:d1:a2:c2:
		c2:03:72:0a:ff:6a:26:38:b0:f7:41:3f:bb:0c:72:
		18:e9:6d:27:34:e2:39:15:b4:19:7e:c6:96:49:72:
		70:6c:79:02:98:1a:5e:5a:22:99:46:47:90:d4:fd:
		8d
	prime1:
		00:e7:e4:27:51:2e:cc:d8:79:23:8e:c8:74:91:9f:
		6c:3c:38:f3:f8:be:bd:fc:0c:d3:29:cc:9f:ac:e5:
		3b:b2:7c:98:5e:a5:38:0a:3b:4d:a9:cc:fe:ed:ff:
		84:a7:b1:0e:5e:b6:48:fc:0f:50:e0:24:8a:7b:2d:
		5a:54:eb:2b:c9:c6:fa:5a:f2:d3:38:2d:40:fa:da:
		e4:e0:a7:61:f8:d1:40:be:a7:47:51:27:e7:c6:c7:
		5e:03:71:44:9e:79:0b:9e:69:af:da:3d:7b:d8:38:
		07:0b:fd:ce:28:f3:98:47:9f:3d:1d:5f:d0:8b:39:
		21:dc:45:10:1c:14:7b:fe:93
	prime2:
		00:d6:94:06:57:21:bd:75:eb:ea:90:14:15:4f:38:
		84:5b:db:09:e8:1f:81:44:b6:3b:8f:8d:6d:a8:2a:
		1b:4f:07:1b:4c:d5:1e:44:27:7d:f0:b3:9f:d1:a8:
		8d:dd:3a:b6:95:cf:e0:50:8e:a8:ef:18:fa:8c:b8:
		e6:16:fe:76:e9:62:78:0a:2d:59:29:92:d7:ed:6c:
		0b:5d:c1:c2:48:4f:b4:63:bb:68:eb:b1:e6:0d:1a:
		b3:40:07:c3:9b:ff:7d:c0:f8:e3:44:d6:13:ba:fd:
		41:45:76:ed:22:0c:ed:45:9f:44:e9:d2:92:ed:c7:
		3f:5b:be:0a:db:4f:76:8b:e3
	exponent1:
		00:e0:d5:f7:45:20:82:5f:35:7d:43:78:9a:85:83:
		34:97:63:85:31:de:07:28:f6:6a:5b:71:da:33:f2:
		03:22:b8:e9:a7:82:bc:46:37:5f:c2:ce:4f:33:05:
		77:62:7c:2a:79:ac:76:31:66:cc:3c:b7:51:49:c3:
		1c:7d:8f:93:62:4d:b9:fa:2a:cc:9f:00:49:ab:b0:
		47:10:87:5a:57:bc:d3:f0:c7:12:3f:de:d8:3c:84:
		9b:63:ed:13:e2:2f:6d:13:88:57:87:db:eb:53:26:
		67:b6:b9:bc:85:3a:42:a0:d7:05:93:90:8e:0c:1f:
		35:f4:73:45:fe:63:e2:21:5f
	exponent2:
		00:c6:c5:46:7e:4e:55:f8:37:7b:08:ce:61:d3:09:
		f2:aa:38:64:9b:ef:1b:4b:30:58:4a:29:63:cc:24:
		7d:39:9e:c6:ae:4c:b9:85:be:e3:8e:26:86:c4:ab:
		94:06:bc:4d:c8:c7:50:ee:ae:c8:54:fc:59:94:23:
		ef:98:9b:4e:41:f1:a2:6b:23:08:f6:56:fd:c9:04:
		8e:1e:e2:ce:fb:37:42:4e:24:9c:13:c1:ae:ee:b2:
		ae:1b:81:55:b5:5b:5d:fd:75:50:ea:42:38:f2:bd:
		89:4a:34:d9:83:f2:5f:95:5f:ed:71:80:4b:f5:11:
		de:62:38:d0:4b:c9:f7:71:ab
	coefficient:
		1f:8e:f6:65:3e:ce:09:4d:2f:e2:2e:a4:0d:37:fc:
		11:85:8c:35:c2:1d:5b:32:21:de:08:8c:87:61:11:
		e7:7f:98:f6:bc:84:ae:f9:b4:31:14:fd:8e:ab:32:
		f9:95:8c:a6:7e:b9:57:72:3f:48:ee:ee:5a:3d:b5:
		9d:3f:0a:05:1b:b9:1b:bc:ae:0c:a3:1e:1f:2a:fe:
		e8:1f:e6:65:64:68:6f:71:99:7c:44:49:3d:46:8b:
		9a:58:d7:04:a5:3d:9d:c7:11:56:34:fd:1d:97:cc:
		1a:f2:48:09:28:75:12:8c:33:c3:36:71:92:ff:df:
		ca:c8:3e:2d:20:61:26:d3
	writing RSA key
	-----BEGIN RSA PRIVATE KEY-----
	MIIEpAIBAAKCAQEAwl7Ogt4TlmWVS4eiOlTIueUAlsYLpcdc5FQ1zENNqM3LZ1JS
	48JVJa5IyX9p5kZ91Qgtb+zlf5h++gTf9Sjze4leWjjgMPZmhXLtLsqnwSCs7nUC
	W0NSMi6Wth6eAvDTCyDwhxIQTQZY0MqM82I5Bv+cliAsswcsxX3TWyLjzlyL1x1M
	U+QtUhhNesqcH3+ZvhkHlDdijDdkakdgYiBshP/lKC6tZH3le6JlqATUukjDbDKc
	C8mx5n0Tnj1jDLO8TO4FG6a5Nx/Wep2OKDvLNeuMo6G/cXL9WBKkUZEtxNuMbk5o
	TQxZDcULfJ8go+/9LBV7809h9vJ4XsJ9Me6NWQIDAQABAoIBABR8H3GlbBUOsbRb
	IBrbsqf83ZoGV1Xqc/zQbzcO5NFklwpVn8zHP2gQPTWXSxbs2Pgpu3gvVGSlMsSw
	3NWeskKT0LDbi609WsK3wQ2MaC+vfOpIxK3Po4sMY+/fvDF9JhDnMNJbcgJcJ+Ih
	ZseD05TMPbmIvI1FtU8/GpZhT/cAlOJriTKdNyRuTUl6cwJwrPE7mVHWS+FCevzj
	0SuxdKiXWwDaa/Dm1IYt9UHLTOPr+lM+KfPd0/qQ4dNLQtScSAVIUy0S0MMHpPUn
	T99I4NGiwsIDcgr/aiY4sPdBP7sMchjpbSc04jkVtBl+xpZJcnBseQKYGl5aIplG
	R5DU/Y0CgYEA5+QnUS7M2Hkjjsh0kZ9sPDjz+L69/AzTKcyfrOU7snyYXqU4CjtN
	qcz+7f+Ep7EOXrZI/A9Q4CSKey1aVOsrycb6WvLTOC1A+trk4Kdh+NFAvqdHUSfn
	xsdeA3FEnnkLnmmv2j172DgHC/3OKPOYR589HV/Qizkh3EUQHBR7/pMCgYEA1pQG
	VyG9devqkBQVTziEW9sJ6B+BRLY7j41tqCobTwcbTNUeRCd98LOf0aiN3Tq2lc/g
	UI6o7xj6jLjmFv526WJ4Ci1ZKZLX7WwLXcHCSE+0Y7to67HmDRqzQAfDm/99wPjj
	RNYTuv1BRXbtIgztRZ9E6dKS7cc/W74K2092i+MCgYEA4NX3RSCCXzV9Q3iahYM0
	l2OFMd4HKPZqW3HaM/IDIrjpp4K8Rjdfws5PMwV3Ynwqeax2MWbMPLdRScMcfY+T
	Yk25+irMnwBJq7BHEIdaV7zT8McSP97YPISbY+0T4i9tE4hXh9vrUyZntrm8hTpC
	oNcFk5CODB819HNF/mPiIV8CgYEAxsVGfk5V+Dd7CM5h0wnyqjhkm+8bSzBYSilj
	zCR9OZ7Grky5hb7jjiaGxKuUBrxNyMdQ7q7IVPxZlCPvmJtOQfGiayMI9lb9yQSO
	HuLO+zdCTiScE8Gu7rKuG4FVtVtd/XVQ6kI48r2JSjTZg/JflV/tcYBL9RHeYjjQ
	S8n3casCgYAfjvZlPs4JTS/iLqQNN/wRhYw1wh1bMiHeCIyHYRHnf5j2vISu+bQx
	FP2OqzL5lYymfrlXcj9I7u5aPbWdPwoFG7kbvK4Mox4fKv7oH+ZlZGhvcZl8REk9
	RouaWNcEpT2dxxFWNP0dl8wa8kgJKHUSjDPDNnGS/9/KyD4tIGEm0w==
	-----END RSA PRIVATE KEY-----


The private key file contains the following data fields:
1. modulus
2. public exponent
3. private exponent
4. prime1
5. prime2
6. exponent1
7. exponent2
8. coefficient

_In the report that you write for this project, explain what all of the above fields are for._

In the screenshot below I convert the colon-separated version of my `prime1` into a Python integer.

![pic](ss.png)

_In the report you produce for this project, include a similar screenshot of your `prime1` converted to an integer.  Use Sage/Python to verity that `prime1*prime2==modulus`._


#### Elliptic curve version

While we will not go deeply into elliptic curves, it is interesting to compare the key files produced by `openssl` for an elliptic curve to those produced by RSA. If you are interested in learning more about the particulars of EC you can read Chapter 9 of the book.  You might also read [this](https://github.com/bitcoinbook/bitcoinbook/blob/develop/ch04.asciidoc) chapter from _Mastering Bitcoin_ which has some fun hands-on exercises.

This is how you generate the private key (adapted from [here)](https://developers.yubico.com/PIV/Guides/Generating_keys_using_OpenSSL.html):

```

$ openssl ecparam -name prime256v1 -genkey -noout -out eckey.pem

```

```
$ cat eckey.pem
-----BEGIN EC PRIVATE KEY-----
MHcCAQEEIBrL00DJFxybCzvbqL5J5Ov66FlwNTfvCrNuBZ+4ecRVoAoGCCqGSM49
AwEHoUQDQgAE2el5ZBpfD4eTUr4GTciUhsz0aKxt9PvH0CW8Dl3g9gk+EO3CEibR
xqId1AmKWB7SQVu62WsXDpG1WtxvwqYDag==
-----END EC PRIVATE KEY-----

```

This key provides roughly the same level of security as the RSA key.  The name `prime256v1` describes a particular curve, also known as `secp256r1`.  The curve used in Bitcoin is `secp256k1`.  These curves and others are defined in official standards documents known as "RFCs" (this comes from Request For Comment).  Here is an [example](https://www.ietf.org/rfc/rfc5480.txt).

_In your report please indicate which is shorter: the EC key or the RSA key. Also generate your own EC key and paste the output into your report._

The decoded version of the key looks like this:

	$ openssl ec -text -in eckey.pem
	read EC key
	Private-Key: (256 bit)
	priv:
		1a:cb:d3:40:c9:17:1c:9b:0b:3b:db:a8:be:49:e4:
		eb:fa:e8:59:70:35:37:ef:0a:b3:6e:05:9f:b8:79:
		c4:55
	pub:
		04:d9:e9:79:64:1a:5f:0f:87:93:52:be:06:4d:c8:
		94:86:cc:f4:68:ac:6d:f4:fb:c7:d0:25:bc:0e:5d:
		e0:f6:09:3e:10:ed:c2:12:26:d1:c6:a2:1d:d4:09:
		8a:58:1e:d2:41:5b:ba:d9:6b:17:0e:91:b5:5a:dc:
		6f:c2:a6:03:6a
	ASN1 OID: prime256v1
	NIST CURVE: P-256
	writing EC key
	-----BEGIN EC PRIVATE KEY-----
	MHcCAQEEIBrL00DJFxybCzvbqL5J5Ov66FlwNTfvCrNuBZ+4ecRVoAoGCCqGSM49
	AwEHoUQDQgAE2el5ZBpfD4eTUr4GTciUhsz0aKxt9PvH0CW8Dl3g9gk+EO3CEibR
	xqId1AmKWB7SQVu62WsXDpG1WtxvwqYDag==
	-----END EC PRIVATE KEY-----

_In your report, execute this command and paste your output._

#### Put it into practice...

For the final exercise, we will use public keys to allow you to use SSH to login to your Cocalc project.  You need to go to Account-->SSH Keys as shown in this screenshot:


<img src="tt.png" alt="Drawing" style="width: 500px;"/>


In the bottom right of the SSH Keys tab there is a link to [this](https://github.com/sagemathinc/cocalc/wiki/AllAboutProjects#create-ssh-key) article explaining how to create SSH keys for use with Cocalc.  Follow those instructions and register your key with Cocalc.

_In your report include a screenshot of your registered key fingerprint from the Cocalc SSH Keys page.  Also include a screenshot showing a successful `ssh` login to Cocalc from the command line._

