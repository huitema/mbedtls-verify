# mbedtls-verify

Trying to reproduce a bug found when using MbedTLS,
when testing sign/verify with PKCS1.
Similar code using ECDSA works fine, but in the case of RSA/PKCS1,
we get an error "the signature of the hash has been computed,
but does not match".

On Linux/MacOS:

Clone the repo, run cmake, then make, then try `mbedtls_verify`.

The cmake finder
assumes that MbedTLS has been installed, so looks in
`/usr/bin/`, `/usr/local/bin/`.

On Windows:

Clone the repo, then open the VS solution at
`./visualc/mbedtls-verify/mbedtls-verify.sln`

The visual studio project assume that MbedTLS has been
cloned in the same folder as `mbedtls-verify`.
