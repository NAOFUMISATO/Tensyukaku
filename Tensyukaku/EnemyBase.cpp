/*****************************************************************//**
 * \file   EnemyBase.cpp
 * \brief  �e�G�̃x�[�X�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include "Game.h"
#include <DxLib.h>
#include "ResourceServer.h"
#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
   Init();
}
EnemyBase::~EnemyBase()
{
}

void EnemyBase::Init()
{
}

void EnemyBase::Process(Game& g) {
   ObjectBase::Process(g);
}

void EnemyBase::Draw(Game& g) {
   ObjectBase::Draw(g);
}