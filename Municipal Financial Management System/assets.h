#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct
{
    int assetID;
    char assetName[50];
    char assetType[30];
    float purchaseValue;
    char department[50];
    char condition[30];
} Asset;

extern Asset
    assets[MAX_ASSETS];
extern int assetCount;

void addAsset();
void displayAssets();
void searchAsset();
void assetManagement();

#endif
