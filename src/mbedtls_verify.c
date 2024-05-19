#ifdef _WINDOWS
#include "wincompat.h"
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <psa/crypto.h>
#include <psa/crypto_struct.h>
#include <mbedtls/error.h>

uint8_t key_data[] = {
    0x30,0x82,0x04,0xa4,0x02,0x01,0x00,0x02,0x82,0x01,0x01,0x00,0xef,0x36,0x61,0x79,
    0x9e,0x29,0x87,0xdf,0x09,0x69,0xe7,0x41,0x36,0xff,0x64,0xaa,0xc5,0x40,0xf4,0x24,
    0xa6,0x85,0xde,0xbd,0x90,0x17,0x3d,0x64,0x07,0xd5,0x14,0xc0,0x38,0x55,0x0c,0x29,
    0xac,0xe8,0xf7,0x64,0x6a,0xf1,0x7f,0x6d,0x07,0x07,0x71,0x64,0xbe,0xa1,0xaf,0x7b,
    0x0f,0x59,0xa2,0x05,0x05,0xe8,0xd8,0xdb,0x3e,0xe9,0x9e,0x89,0x43,0x9b,0x1a,0x93,
    0xf6,0xd5,0x8e,0x70,0x71,0x89,0x4f,0x2f,0x86,0xa8,0x8e,0x5a,0xf0,0x30,0x1f,0xde,
    0x3b,0x13,0x82,0xa6,0xe4,0x72,0x41,0x34,0x52,0x49,0xed,0x61,0x0c,0xfb,0xdd,0x24,
    0x00,0x50,0x76,0x6b,0x21,0x0c,0xfe,0x59,0x48,0x40,0x4b,0x75,0x44,0xa0,0xac,0xd9,
    0xf8,0x29,0x68,0x48,0x0e,0x31,0x63,0xd4,0x01,0xd7,0x20,0xca,0x9e,0xa9,0x35,0xde,
    0xb4,0x5b,0x91,0x80,0xdc,0xc7,0x76,0xd6,0xd7,0x43,0x1f,0x94,0x58,0x18,0xac,0xd8,
    0x1e,0xaa,0x64,0x9b,0xaa,0x48,0x0a,0xdb,0xda,0x6b,0x15,0x38,0x2f,0x03,0xe6,0x03,
    0x73,0x9c,0xf3,0xe5,0x43,0x0e,0xc5,0x6d,0xd3,0xc2,0x68,0xb3,0x57,0x49,0xbe,0x86,
    0x9c,0x8d,0x04,0xd2,0xe8,0xfa,0x42,0x66,0x25,0x03,0x0f,0x6c,0xea,0x79,0x20,0x3f,
    0xfc,0xf1,0x8d,0xf1,0x65,0x76,0xa3,0xcd,0x52,0x9a,0xc6,0x70,0x4a,0x93,0xc2,0x60,
    0x1b,0xf1,0x55,0x6d,0x77,0xb5,0xdb,0x00,0xd6,0x2b,0xce,0xe6,0xd9,0xe0,0xd9,0xfa,
    0xfd,0x65,0xeb,0x0a,0xb5,0x71,0x59,0x49,0xa1,0xff,0xb4,0xa9,0x81,0xdc,0x1a,0xfc,
    0x8e,0x0d,0xaf,0x52,0x47,0xbf,0xd1,0xc7,0xc8,0xbd,0xb3,0xff,0x02,0x03,0x01,0x00,
    0x01,0x02,0x82,0x01,0x00,0x45,0x4f,0x7f,0x6c,0xca,0xac,0x03,0xe7,0x57,0x05,0xed,
    0x70,0x92,0xeb,0xeb,0x12,0x23,0xf7,0x4f,0x06,0x33,0x8d,0xc4,0x5d,0x2e,0x9b,0xdd,
    0x38,0xd7,0xa0,0x20,0xd4,0x15,0x3e,0x67,0x38,0xc8,0x15,0xf4,0x60,0x8f,0x30,0x0c,
    0x18,0xde,0x19,0x84,0xfc,0x88,0xd3,0xb6,0x51,0xb4,0xbf,0xe6,0xd7,0x07,0xc0,0x50,
    0xdd,0x2d,0xdc,0x69,0x08,0x22,0xa3,0x95,0x4e,0xdc,0x0d,0x42,0xa9,0x47,0xec,0x5e,
    0x1a,0x4a,0x2d,0x1a,0x9a,0x34,0xcf,0xec,0xdb,0xea,0x48,0x1b,0xea,0x19,0x75,0x15,
    0x79,0x80,0x82,0x55,0x1a,0x72,0xb5,0xa3,0x7c,0xa3,0xee,0xac,0x71,0x1b,0xf1,0x74,
    0xdd,0x0f,0xb7,0x39,0x65,0xf0,0x0d,0x92,0x27,0xd1,0xe4,0xc5,0x87,0x63,0x3d,0x62,
    0x4c,0x72,0x80,0x0f,0xca,0xb6,0x44,0x44,0x65,0x6b,0xfc,0x43,0xca,0x99,0xa5,0xd3,
    0xa9,0x25,0x20,0x58,0x67,0x21,0x84,0xf7,0xb2,0x6a,0xcb,0xfc,0x86,0x73,0xe0,0xd0,
    0x56,0x9a,0x1a,0xf4,0x1f,0x16,0xc2,0x72,0x1d,0x52,0x7e,0x3b,0x4e,0x46,0x5f,0xb1,
    0xbc,0xea,0x18,0x86,0x19,0xc5,0xab,0x49,0x40,0x30,0xb5,0x8f,0xb6,0x3e,0x17,0xc4,
    0xa8,0xef,0x30,0x5b,0x52,0x1a,0x73,0xed,0x8a,0x80,0x4d,0x0c,0x1f,0xe4,0x47,0xe6,
    0x2b,0x6c,0x70,0xbe,0x5c,0x1f,0x77,0x0c,0xa4,0xab,0xa7,0xdf,0x12,0xbd,0x8c,0xfd,
    0x79,0xda,0xd3,0x6d,0xb4,0x1b,0x62,0x59,0x94,0x6a,0xb7,0x0a,0xcd,0x97,0xf4,0x64,
    0xfd,0x3e,0xdf,0x4e,0x4b,0xce,0x81,0xcf,0xe1,0x0b,0xe3,0xa1,0x0b,0xa3,0x4b,0x59,
    0xc9,0xf1,0xd0,0x7b,0xf9,0x02,0x81,0x81,0x00,0xfb,0x38,0x78,0x93,0x66,0xde,0xe9,
    0xf8,0x50,0x1b,0xe0,0xa1,0x88,0x6d,0xd4,0x7b,0x92,0xbf,0x90,0x7d,0xa9,0xae,0xac,
    0x86,0x06,0xeb,0x3a,0xd7,0x01,0xe7,0xb7,0xc5,0xd9,0x6a,0xfa,0x81,0x7a,0xf1,0x32,
    0xe2,0x97,0x66,0xbc,0x9e,0x90,0xd5,0x36,0xbd,0x67,0x66,0x02,0x22,0xaa,0x8d,0x9a,
    0x54,0xdd,0x8d,0x9e,0x81,0xdf,0x99,0x6f,0x00,0xaf,0x18,0x14,0x84,0xc6,0xcb,0x43,
    0x15,0x57,0xa2,0xb9,0x34,0x56,0x15,0x7e,0x10,0x0b,0x58,0x24,0x02,0xda,0xbd,0xc1,
    0xea,0xe1,0xf7,0xf4,0x54,0x34,0x98,0x3a,0x37,0x81,0x2e,0x59,0x8d,0x89,0x54,0xcd,
    0xbb,0xba,0xec,0xb1,0x85,0x9f,0x25,0xfe,0xa7,0x23,0x2b,0xda,0x8c,0x65,0x84,0x8d,
    0x5f,0x09,0x8d,0xd5,0x72,0x15,0xd0,0x00,0xeb,0x02,0x81,0x81,0x00,0xf3,0xc3,0x6d,
    0x0b,0x04,0x8e,0x69,0x9d,0x5f,0x5a,0x6c,0x8d,0x02,0x05,0xc4,0x01,0x7d,0x49,0xc7,
    0x85,0xcb,0x15,0x88,0x23,0x70,0x0f,0xd8,0x05,0x75,0xbd,0x81,0xf4,0x34,0x01,0xfb,
    0x9f,0x07,0x7e,0x3a,0xcb,0x9d,0xcf,0xb2,0x08,0xd7,0xd6,0x50,0x7e,0x05,0xb7,0x20,
    0x71,0x8f,0xe8,0xe5,0x6e,0xc5,0xd1,0xbd,0xc0,0xd1,0x1e,0x0a,0xe4,0xb4,0xa1,0x94,
    0xf0,0xaa,0xf2,0x20,0x76,0x0c,0x2f,0x95,0x9e,0x92,0xb0,0x4e,0x0a,0x3c,0xca,0x58,
    0x7e,0x55,0x90,0x8f,0xcb,0x60,0x66,0x30,0xad,0x23,0xae,0xb9,0xb2,0xa9,0x67,0xa0,
    0x3f,0x3c,0x20,0x3f,0x49,0x69,0xfb,0xb9,0x7f,0xa9,0x6f,0x0b,0x0c,0x89,0x9e,0x62,
    0x2f,0x27,0x5a,0x8a,0x9d,0xe9,0xfd,0x72,0x7b,0x88,0x89,0x74,0x3d,0x02,0x81,0x81,
    0x00,0x94,0x80,0x29,0x26,0x58,0xe4,0xe4,0x41,0x58,0x79,0x62,0x2b,0x9a,0x4d,0xf2,
    0x10,0xaa,0x0a,0x7b,0x0b,0x0d,0x46,0xa7,0xcd,0x02,0x42,0x02,0xa2,0x1e,0x0a,0x2f,
    0x63,0xd0,0xc5,0xa0,0x16,0xf1,0xe9,0xaa,0x3e,0xaf,0x68,0x97,0x8e,0xd3,0xe6,0x75,
    0x59,0x38,0xc9,0xdf,0xf1,0x46,0x08,0x36,0x76,0x7c,0x10,0xbe,0xe5,0xde,0x9b,0x00,
    0x36,0xd3,0x49,0xd4,0xb7,0x38,0x1b,0xe7,0x27,0xb2,0x8a,0x0a,0x18,0x99,0xda,0x52,
    0x8e,0x81,0x66,0x34,0xc3,0x4b,0x32,0x68,0x72,0xc3,0xe8,0xa2,0x91,0x34,0x15,0xd8,
    0x33,0xff,0x34,0xba,0xd3,0x23,0x9e,0xf1,0x8e,0x4b,0x4c,0xa7,0x13,0x69,0xa4,0x38,
    0x07,0xec,0x8e,0x7b,0xbe,0x0a,0x34,0x74,0xac,0xfd,0x24,0xce,0x4b,0x86,0x01,0x52,
    0xc9,0x02,0x81,0x80,0x08,0xa9,0xa4,0x41,0x64,0xfb,0x0e,0xa3,0xca,0x14,0xb3,0x90,
    0xdb,0x46,0x8b,0x2d,0xa6,0x5f,0x2d,0xd9,0x02,0x5b,0x94,0x87,0xf5,0xde,0x8a,0x45,
    0xbf,0x66,0x69,0xac,0xdd,0x00,0x49,0x09,0xe0,0xc1,0x4a,0xa3,0x9b,0xcb,0x1a,0xbf,
    0x97,0xb4,0x05,0x0e,0x45,0x73,0xb9,0x92,0x6f,0x93,0xce,0x3b,0x7e,0x8a,0x32,0x9d,
    0x1c,0x91,0x5d,0xbf,0xbc,0xef,0x95,0x14,0x6c,0x6e,0xc8,0x5a,0x89,0x9a,0x53,0x4d,
    0xdc,0x56,0xa9,0x9f,0x51,0x83,0xbb,0x5b,0x59,0xfd,0x16,0x2f,0x1b,0x10,0xe6,0x9f,
    0xf0,0x89,0xb0,0x0d,0xba,0x59,0x75,0x67,0x69,0xe2,0x97,0x7d,0x2b,0x68,0x07,0xb2,
    0x92,0xb9,0xe0,0x81,0xa4,0x8e,0x5d,0x5c,0xe1,0xa0,0x25,0x16,0xf1,0x8e,0xd1,0x37,
    0xb4,0xa5,0x75,0xdd,0x02,0x81,0x81,0x00,0xad,0x98,0xbb,0x53,0x24,0xf2,0x74,0x67,
    0xef,0x67,0xf3,0x90,0xbc,0x90,0x1a,0x27,0x93,0x63,0x02,0x9c,0x3f,0x49,0x4d,0x85,
    0xa8,0x0d,0x0c,0xcd,0x31,0x81,0x9a,0x6e,0xd8,0x73,0x4a,0xa2,0x6a,0x70,0x47,0xa4,
    0x76,0xf8,0x6b,0xf3,0x65,0xe4,0x70,0x73,0x3e,0xaf,0xaf,0x9c,0x8a,0xb8,0xdd,0x42,
    0xbe,0x10,0x8f,0xbf,0xf6,0x6d,0xf6,0x5e,0xb0,0x79,0x79,0x5c,0xbb,0xe8,0x24,0x30,
    0x75,0x60,0x92,0x17,0x9c,0xd2,0x4e,0x10,0xbc,0x1b,0x92,0xda,0xc9,0xad,0x72,0xdc,
    0x74,0x9f,0x8c,0x32,0xf3,0xef,0x04,0x03,0x1a,0x87,0xfb,0x6a,0xaf,0x60,0xea,0x81,
    0x31,0x9f,0x58,0xb0,0xed,0xf4,0xf2,0x62,0x08,0x95,0x6c,0xb8,0xdd,0xa4,0x0f,0xdb,
    0x68,0x58,0x75,0x74,0xf2,0x96,0x34,0x3a
};

int main(int argc, char ** argv)
{
    int ret = 0;
    psa_status_t status;
    uint8_t hash_buffer[64];
    uint8_t sign_buffer[512];
    uint8_t pubkey_data[512];
    size_t hash_length = 0;
    size_t sign_length = 0;
    size_t pubkey_length = 0;
    psa_algorithm_t hash_algo = PSA_ALG_SHA_256;
    psa_algorithm_t sign_algo = PSA_ALG_RSA_PKCS1V15_SIGN(hash_algo);
    psa_key_type_t pubkey_type = PSA_KEY_TYPE_RSA_PUBLIC_KEY;

    if ((status = psa_crypto_init()) == PSA_SUCCESS) {
        mbedtls_svc_key_id_t key_id;
        psa_key_attributes_t attributes = psa_key_attributes_init();

        psa_set_key_usage_flags(&attributes, PSA_KEY_USAGE_SIGN_HASH|PSA_KEY_USAGE_SIGN_MESSAGE);
        psa_set_key_algorithm(&attributes, sign_algo);
        psa_set_key_type(&attributes, PSA_KEY_TYPE_RSA_KEY_PAIR);

        status = psa_import_key(&attributes, key_data, sizeof(key_data), &key_id);
        if (status == PSA_SUCCESS) {
            if ((status = psa_hash_compute(hash_algo, key_data, sizeof(key_data), hash_buffer, sizeof(hash_buffer), &hash_length)) !=
                PSA_SUCCESS) {
                printf("Computing the hash failed.\n");
            }
            else if ((status = psa_sign_hash(key_id, sign_algo, hash_buffer, hash_length,
                sign_buffer, sizeof(sign_buffer), &sign_length)) != 0) {
                printf("Computing the signature failed.\n");
            }
            else if ((status = psa_export_public_key(key_id, pubkey_data, sizeof(pubkey_data), &pubkey_length)) != 0) {
                printf("Cannot export public key, status = %d\n", status);
            }
            else {
                mbedtls_svc_key_id_t pubkey_id;
                psa_key_attributes_t pubkey_attributes = psa_key_attributes_init();

                psa_set_key_type(&pubkey_attributes, pubkey_type);
                psa_set_key_algorithm(&pubkey_attributes, sign_algo);
                psa_set_key_usage_flags(&pubkey_attributes, PSA_KEY_USAGE_VERIFY_MESSAGE | PSA_KEY_USAGE_VERIFY_HASH);

                if ((status = psa_import_key(&pubkey_attributes, pubkey_data, pubkey_length, &pubkey_id)) != 0) {
                    printf("Cannot import public key, status = %d\n", status);
                }
                else {
                    if ((status = psa_verify_message(pubkey_id, sign_algo, key_data, sizeof(key_data), pubkey_data, pubkey_length)) != PSA_SUCCESS) {
                        char const* str_err = "-";

                        switch (status) {
                        case PSA_ERROR_NOT_PERMITTED: /* The key does not have the PSA_KEY_USAGE_SIGN_MESSAGE flag, or it does not permit the requested algorithm. */
                            str_err = "Incompatible key";
                            break;
                        case PSA_ERROR_INVALID_SIGNATURE: /* The calculation was performed successfully, but the passed signature is not a valid signature. */
                            str_err = "Invalid signature";
                            break;
                        case PSA_ERROR_NOT_SUPPORTED:
                            str_err = "Illegal parameter";
                            break;
                        case PSA_ERROR_INSUFFICIENT_MEMORY:
                            str_err = "Insufficient memory";
                            break;
                        default:
                            break;
                        }
                        printf("Cannot verify signature with public key, status = %d (%s)\n", status, str_err);
                    }
                    else {
                        printf("Success\n");
                    }
                    psa_destroy_key(pubkey_id);
                }
            }
            psa_destroy_key(key_id);
        }
        mbedtls_psa_crypto_free();
    }
    return (status == 0) ? 0 : -1;
}
