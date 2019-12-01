//
//  BRChainParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRChainParams_h
#define BRChainParams_h

#include "BRMerkleBlock.h"
#include "BRSet.h"
#include <assert.h>

typedef struct {
    uint32_t height;
    UInt256 hash;
    uint32_t timestamp;
    uint32_t target;
} BRCheckPoint;

typedef struct {
    const char * const *dnsSeeds; // NULL terminated array of dns seeds
    uint16_t standardPort;
    uint32_t magicNumber;
    uint64_t services;
    int (*verifyDifficulty)(const BRMerkleBlock *block, const BRSet *blockSet); // blockSet must have last 2016 blocks
    const BRCheckPoint *checkpoints;
    size_t checkpointsCount;
} BRChainParams;

static const char *BRMainNetDNSSeeds[] = {
    "dnsseed01.moonypool.com.", "dnsseed02.moonypool.com.", "dnsseed03.moonypool.com.", NULL};

static const char *BRTestNetDNSSeeds[] = {
    "testnet-seed01.moonypool.com.", NULL
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRMainNetCheckpoints[] = {
    {    26700, uint256("513f2d61fc89206109d4547b100e0e4ac0a12339957c1ccd8b927a0ff641cdfe"), 1391581252, 0x1c00bd13 },
    {    66600, uint256("881a7edf40cb76722a89abe3a9b32b5af59928b48d178c1e52dd888a69d289c9"), 1396548592, 0x1c0ec63d },
    {    66618, uint256("1bf88ab406ff6ea9f43d8fff61ada69189443de12d143f2ebb7ddb019b54dee2"), 1396551065, 0x1c0ec818 },
    {  1000000, uint256("d806ec36632672626e7a8e764948ea09ff69cf0360edc427008accf68b8fcf6d"), 1481024430, 0x1c1a1b5b },
    {  1100000, uint256("6988ca75c6bcba6253f4f775788785e71e1efae72c05d678386c3053b2c15863"), 1490248136, 0x1c0edd4c },
    {  1110000, uint256("084bb5c11d303ad2e061c81921fbde3f07197898e63a59836399218bf97eabc1"), 1494673551, 0x1c155f73 },
    {  1112500, uint256("e78124b931c6628967b756a1200bf9b5917693536eaac520f876dfe2b35e6637"), 1495626117, 0x1c02f0cb },
    {  1112513, uint256("5f4fdf9124764fa74652d0e2cbdc170b407c5c96e93d9b78626eaea98c496601"), 1495629733, 0x1c025f14 },
    {  1212505, uint256("e45b3ba0d0f98922fa848d277917833071629523a10ce72ef5db7884f39c78c3"), 1520505826, 0x1b21d545 },
    {  1312500, uint256("ef1b810abf761cc054d89a1d1191b73d29d898abb62f72a57c3caf6cbf9547d8"), 1534724248, 0x1c00c8af },
    {  1412503, uint256("7965ed48962d2959ce054970c4ea64094ebc9e0af42dca14a77157e33f04179c"), 1544207015, 0x1c009d67 },
    {  1512502, uint256("93bcbe8ff0f938628b5fdd29b46c6d7d859d440bba175e8118a4377be5e67897"), 1554057890, 0x1c00b5f5 },
    {  1612501, uint256("6e3713dea2fa389ded6e9140068874d49131440147a6385eb4ffcc00595a52af"), 1563965011, 0x1c009e14 },
    {  1712500, uint256("b87d10af80ab9e966fcb1c0c95cac25c3c74a22e7f9fd04606e992741dfaa38b"), 1573719222, 0x1c011390 }
};

static const BRCheckPoint BRTestNetCheckpoints[] = {
    {       0, uint256("ae5047b8182d7e9c7f6cdefdb12bc08a95ca7884126e56b15b5082a5ce18e4d7"), 1540452872, 0x1e0ffff0 },
	{   10983, uint256("69bc203faa0a93efa3e11c9d8b260d48ff49eb54eb877196f433642190008994"), 1540787938, 0x1e0fffff },
	{  133658, uint256("ca85d40cfaa1e19ea2f2a6982a89538022c6eb58737f293fdbb6ff522b8c31b1"), 1541156068, 0x1e0fffff },
	{  186531, uint256("cd345adfaca4cf2fd067888d5392bb961697e40e7786b8e9bf9f7723320a6354"), 1541215740, 0x1e0fffff },
	{  253366, uint256("c057d1926b822b865a29a77c1c2c71dc5c9b5b35ac42d30005ed05fb8ddd2b30"), 1541294474, 0x1e0fffff },
	{  332184, uint256("2852b3d257277ee3a7045de59e69a4940a0b07aa17507088c83aa34526ede70a"), 1541382243, 0x1e0fffff },
	{  384254, uint256("561a12ecbca0592ca572089cbcd87d974a1d396d93b69fcdaf74e97d241581aa"), 1541450440, 0x1e0fffff },
	{  384418, uint256("370d144c6e265183fcab51f8b960a0ad9d87cee6b16f3bbd2c201f16edfba9ad"), 1541450664, 0x1e0fffff },
	{  594398, uint256("2629ced17214cbbee8bcdf6e764ff5d591382af7d4724e715ad073c97b648706"), 1541664241, 0x1e0fffff },
	{  650504, uint256("c28ae82187062144ee8ff547269f4349459ea43e5c9acfa4e4f1d710a725da00"), 1541741749, 0x1e0fffff },
	{  700501, uint256("0dee1b499737d8a4bbff808fd8c4b8db4884029fbec7cc5608cffbe4d14b28ca"), 1541823017, 0x1e0fffff },
	{  800504, uint256("6afc0c1a69f1163eb31317c0e804bb1b74ffe07a1cfe19e85c204b6a0943ee3c"), 1542024559, 0x1e0fffff },
	{  900504, uint256("7fd5a418500928cf3efc777d830b1c332375f1916f37d4324f0db0faedd5d3b5"), 1542167143, 0x1e0fffff },
	{  1000502, uint256("336b7db51e049057a8d93d5bec666fad502026e5f2e8c4e67265a3e8c6f6fa8b"), 1542271845, 0x1e0fffff },
	{  1100547, uint256("ad475bf4449d7b2294d37374bdcec5f70b972ae188abc1ba480518c92a2e01b9"), 1542617102, 0x1e0fffff },
	{  1200506, uint256("6dd82e370ff21c503cd67606eacf2d318942d9e9c708fde45bd74a0b86ff5d84"), 1542684509, 0x1e0fffff },
	{  1300501, uint256("2b2c1b41b7068f231306c5983f31d6e5c0b86920028d416f1bf8c52c173869fc"), 1548127014, 0x1d070a3c },
	{  1400501, uint256("5d86152c570a575b53bf552d573dcfa66ff721dba37ba06b8dc1e08e762d0089"), 1558426016, 0x1d0b2765 },
	{  1500502, uint256("5ac72cb8cfbb1b13e862a7368ce599fc502768c79278b758f17d9825c134c9d3"), 1568042950, 0x1d107b45 },
	{  1524769, uint256("4f870d3dd78b80aebcddd4b35551f28105cd51ccea1d0cec10290b24f5f60907"), 1570342103, 0x1d0a0a59 }
};

static int BRMainNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    // const BRMerkleBlock *previous, *b = NULL;
    // uint32_t i;

    // assert(block != NULL);
    // assert(blockSet != NULL);

    // // check if we hit a difficulty transition, and find previous transition block
    // if ((block->height % BLOCK_DIFFICULTY_INTERVAL) == 0) {
    //     for (i = 0, b = block; b && i < BLOCK_DIFFICULTY_INTERVAL; i++) {
    //         b = BRSetGet(blockSet, &b->prevBlock);
    //     }
    // }

    // previous = BRSetGet(blockSet, &block->prevBlock);
    // return BRMerkleBlockVerifyDifficulty(block, previous, (b) ? b->timestamp : 0);
    return 1;
}

static int BRTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRMainNetParams = {
    BRMainNetDNSSeeds,
    44664,       // standardPort
    0xe8c0f7f9, // magicNumber
    0,          // services
    BRMainNetVerifyDifficulty,
    BRMainNetCheckpoints,
    sizeof(BRMainNetCheckpoints) / sizeof(*BRMainNetCheckpoints)};

static const BRChainParams BRTestNetParams = {
    BRTestNetDNSSeeds,
    14664,      // standardPort
    0xf1c8d2f3, // magicNumber
    0,          // services
    BRTestNetVerifyDifficulty,
    BRTestNetCheckpoints,
    sizeof(BRTestNetCheckpoints) / sizeof(*BRTestNetCheckpoints)};

#endif // BRChainParams_h
