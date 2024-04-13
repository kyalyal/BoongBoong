// Copyright Epic Games, Inc. All Rights Reserved.


#include "BoongGameModeBase.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"


//¸ÞÀÎ·¹º§·Î ÀüÈ¯ÇÑ´Ù.
void ABoongGameModeBase::ChangeMainLevel()
{
    //»ó±â LSK_Test_Start_Level // °ÇÁÖMain_Circit
    UGameplayStatics::OpenLevel(this, "Main_Circit");
}
//Ã³À½½ÃÀÛ·¹º§·Î ÀüÈ¯ÇÑ´Ù.
void ABoongGameModeBase::ChangeStartLevel()
{
    UGameplayStatics::OpenLevel(this,"LSK_Test_Start_Level");
}
//ÇÃ·¹ÀÌ¾î »ý¼º
void ABoongGameModeBase::ReSpawn()
{
    
}
//Á¦ÇÑ½Ã°£ Å¸ÀÌ¸Ó¸¦ ½ÇÇàÇÑ´Ù.
void ABoongGameModeBase::StartTimer()
{
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ABoongGameModeBase::CalculateTimer, 1.0f, true, 1.0f);
}
//Å¸ÀÌ¸Ó ÇÚµéÀ» ¸ØÃß°Å³ª ÃÊ±âÈ­ÇÒ ¶§ »ç¿ëÇÑ´Ù.
 void ABoongGameModeBase::StopPlayerTimer()
 {
     GetWorldTimerManager().ClearTimer(TimerHandle);
 }

 //Å¸ÀÌ¸ÓÀÇ ½Ã°£À» °è»êÇÏ¿© ºÐ°ú ÃÊÀÇ º¯¼ö¿¡ °ªÀ» »ðÀÔÇÑ´Ù.
 void ABoongGameModeBase::CalculateTimer()
 {
     // ÃÑÁ¦ÇÑ ½Ã°£ÀÌ 1ÃÊ¾¿ °¨¼ÒÇÑ´Ù.
     PlayTime--;

     // ºÐ°ú ÃÊ °è»êÇÏ¿© º¯¼ö¿¡ »ðÀÔÇÑ´Ù.
     PlayTimeMin = PlayTime / 60;
     PlayTimeSec = PlayTime % 60;
     UE_LOG(LogTemp, Log, TEXT("Remaining Time: %02d:%02d"), PlayTimeMin, PlayTimeSec);
     // Å¸ÀÌ¸Ó Á¾·á ½Ã ½Ç°ÝÃ³¸®ÇÏ°í Å¸ÀÌ¸Ó ÇÚµéÀ» ÃÊ±âÈ­ÇÑ´Ù.
     if (PlayTime <= 0) 
     {
         TestDisqualification();
         StopPlayerTimer();
     }
 }
 //PlayTimeÀ» 10ºÐÀ¸·Î ÃÊ±âÈ­ÇÑ´Ù.
 void ABoongGameModeBase::ResetPlayTime()
 {
     PlayTime = 600;
 }

 //5Á¡ÀÌ °¨Á¡ÀÌ µÇ°í ½Ç°ÝÁ¡¼ö 60Á¡º¸´Ù ³·¾ÆÁö¸é ½Ç°ÝÃ³¸®°¡ µÈ´Ù.
 void ABoongGameModeBase::MinusPlayerScore()
 {
     PlayerScore -= 5;
     if (PlayerScore < 60) 
     {
         TestDisqualification();
         StopPlayerTimer();
     }

 }

 //ÇÃ·¹ÀÌ¾îÀÇ Á¡¼ö°¡ 100Á¡À¸·Î ¸®¼ÂµÈ´Ù.
 void ABoongGameModeBase::ResetPlayerScore()
 {
     PlayerScore = 100;
 }

 //µµÂø¼±¿¡ µµ´Þ½Ã ÇÃ·¹ÀÌ¾î°¡ ÇÕ°ÝÀÎÁö ºÒÇÕ°ÝÀÎÁö ÆÇ´ÜÇÑ´Ù. 
 void ABoongGameModeBase::JudgePass()
 {
     StopPlayerTimer();
     if (PlayerScore >= 80) //Á¡¼ö 80Á¡ÀÌ ³ÑÀ¸¸é Åë°ú
     {
         PlayerPass();
     }
     else //¾Æ´Ò°æ¿ì ºÒÇÕ°ÝÃ³¸®
     {
         PlayerFail();
     }
 }
 //#ºí·çÇÁ¸°Æ®·Î ÇØ´ç UI¸¦ °¡Á®¿Í¼­ ¼³Á¤ÇØ¾ßÇÔ
 //ÇÃ·¹ÀÌ¾î°¡ ÇÕ°Ý ÇßÀ» ¶§
 void ABoongGameModeBase::PlayerPass()
 {
    
 }
 //ÇÃ·¹ÀÌ¾î°¡ ºÒÇÕ°Ý ÇßÀ» ¶§
 void ABoongGameModeBase::PlayerFail()
 {

 }

 //½ÃÇè ½Ç°ÝÃ³¸®°¡ µÇ¾úÀ» ¶§
 void ABoongGameModeBase::TestDisqualification()
 {

 }
 
 void ABoongGameModeBase::TestTest()
 {
     CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), MainWidget);
     CurrentWidget->AddToViewport();
 }
 void ABoongGameModeBase::BeginPlay()
 {    
     Super::BeginPlay();
     
 }
