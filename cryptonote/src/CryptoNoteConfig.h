//  GNU nano 2.5.3                           Archivo: CryptoNoteConfig.h                                                    Modificado  

// Copyright (c) 2018, CryptoLuKa developers
// Copyright (c) 2017, Intense Coin developers
// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include <cstddef>
#include <cstdint>
#include <limits>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 90; // seconds tiempo de generacion de bloques 15 min super confirmad
// si se pone 10 seg generaria muchos bloque sguerfanos,, recomienda  60 hasta 120segundos entre mas rapido mas genera para mineros
const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;// el maximo de bloques de la cadena
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 5000000000;// cuanto pesara un bloque. 
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;//1byte
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x2de7e1; // addresses start with "L" el prefijo de como iniciaria nue$
//billetera 
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;//cuantos bloques  confirmaciones para liberar saldos  
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 270; // DIFFICULTY_TARGET * (DIFFICULTY_WINDOW_V4 - 1) / 20 adminison
// de futuro es en segundo para evitar eltema del 51%  4miunutos imedio

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;//no tocar
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V4          = 11;//no tocar por que vienen de calculos matematicos

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                  = UINT64_C(10000000000000000); // 100Millones, es la validacnion cuantas monedas
//genraremos al tanto años en tantos ceros 100millones,  ocho ceros para decimales se trabaja con 8 decimales
const uint64_t FINAL_SUBSIDY_PER_MINUTE      = UINT64_C(20000000); // 0.20 LUK emision de cola donde se  llega al topo
//de las 100millones,   una regla de incentido despues de llegar al topo poder pagar tambien
// por que tantos millones, recomendaciaon no debes terner una criptomoneda con tanto suply
// se necesita por que es la forma para pagar la recompensa
const unsigned EMISSION_SPEED_FACTOR               = 22; //es el ultimo factor para la formula de recompensas
//en los años que la moneda se emita a mayor factor mayor tiempo. 18 -22  22  es a 35años, se reocmienda de 18 a 19

static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");// verifica que se un numero
// que sea menor o igual a 8

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW                  = 100;// reward zone, ventanaminima de bloque es 100
// se recomienda 100,  si los bloques se generan grandes pegan la red 100mb
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE        = 1000000; //size of block (bytes) after which reward for block calcu$
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2     = 1000000;//la version de bloques en que se esta
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1     = 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;

const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;//los  bites  que pude pesar la transaccion del minero mas de eso
//es  una transaccion invalida
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;// 8 posiciones de decimales maximo 12
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000);    // pow(10, 5) pago minimo fee 0.0001 par
//a mandar info
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000);    // pow(10, 5) cuando la red no puede calcula
//el fee  lo hace el dust si es muy pequeño cobrale el dust

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;//24horas 60 minuto 60 segundo
//60 = 1440 x recompensa
//90 = 960 x recompensa
//120 = 720 x recompensa
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;// par evadir el ataque  51%
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t  DIFFICULTY_BLOCKS_V2 = 17;
const size_t  DIFFICULTY_CUT_V2  = 6;
const size_t  DIFFICULTY_WINDOW_V2 = DIFFICULTY_BLOCKS_V2 + DIFFICULTY_CUT_V2 * 2;
const size_t  DIFFICULTY_WINDOW_V4 = 61;


const size_t   MAX_BLOCK_SIZE_INITIAL                           = 100 * 1024;// tamaño incial del bloq
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR            = 100 * 1024;//maximo de la velocidad
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR_V2         = 35 * 100 * 1024;//
const size_t   MAX_BLOCK_SIZE_ALLOWED_EVERY_N_BLOCK                             = 5;//cada 5 bloques crece los 102kilo
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR          = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;//duplicar el tamaño del 
//bloque

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS        = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS       = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                   = 60 * 60 * 24;     //seconds, one day llegada de tiempo de vida
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME    = 60 * 60 * 24 * 7; //seconds, one week tiempo de vida de mempool
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED$
// que da un registro en la segunda cadena , cadena donde van los bloques huerfanos
const size_t   FUSION_TX_MAX_SIZE = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 15 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;// maximo de cuentas para enviar  una transaccion
//para la pool  se multiplica por n para poder mandar un pago a varias cuentas
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;// cantidad de regreso  como vueltos entrar 4
// todas las monedas lo hacen , es como si pagaras con billete grande  y da vuelto

const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX                = 2000000;//la altura del bloque para empesar a validar
//en este caso validar que no se dupliquen las key index, recomendaion poner en cero
const uint32_t UPGRADE_HEIGHT_V2                             = 100;//colocar 1
const uint32_t UPGRADE_HEIGHT_MAX_BLOCK_SIZE                 = 120;//colocar 2
const uint32_t UPGRADE_HEIGHT_V3                             = 200;//colocar 3
const uint32_t UPGRADE_HEIGHT_V4                             = 144999;//colocar 4 para uqe haga actualizacion
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;// percent de concenso el resto que da fuera de la actualizacion
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks calculo diario
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks  no tocar

static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");//validacion estatica
//  es como de 0 a 100 si no da error
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

//los nombre de los archivos como llamaremos en el .coin  recomienda no cambiar el nombre
const char     CRYPTONOTE_BLOCKS_FILENAME[]                     = "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]               = "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                   = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                          = "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                         = "miner_conf.json";
} // parameters


const char     CRYPTONOTE_NAME[]                             = "emet";//nombre de la moneda

//es el orden de las versiones de los bloques y transacciones
const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing cuantos
//bloques voy llamado de los headers
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading es por 
//multiplos de 12 por eso tiene 128 en al sincronizacion bajara asi
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;// es para habilitar modo fast


const int      P2P_DEFAULT_PORT                              =  48000;//puertos para sincronizar 
const int      RPC_DEFAULT_PORT                              =  48001;//puerto para hacer peticiones 

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;// los nodos nuevosal sincronizar  un nodo se hacen dos listas
// una de nodos wl y los bl,   
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;// la cache de los nodos que tengo y no debo volver a pedir

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB  dejar fijo
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;//  cantidad de conexiones por defecto super bien
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;//porcentual de conexiones entrantes
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds cada cuanto tiempo tedas cuenta
// que faltna nodos, en line si te falta uno el vuelve a buscar si le falta uno
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet sizes,  
//si el bloque es grande calcula lo maximo que puedo traer entre encabezado  y  128 bloques, lo que alcanse de 4.76mb
//para evitar corromper la informacion
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;//informacion de peers traer simultaneos datos de nodo
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds espera para renovar conexion
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds

const char     P2P_STAT_TRUSTED_PUB_KEY[] = "";// otra encriptacion mas.....

//
const char* const SEED_NODES[] = {
        "192.168.1.99:48000",
        "192.168.1.100:48000",
};

struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const CheckpointData CHECKPOINTS[] = {
        { 9000, "3e7b089856003ff9706e8db0a530bfec03d91143491086a2835fcdc2a38373e0"}, // Genesis

};
}

#define ALLOW_DEBUG_COMMANDS
