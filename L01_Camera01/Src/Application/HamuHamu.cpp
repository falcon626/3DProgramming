#include"HamuHamu.h"

HamuHamu::HamuHamu()
{
}

HamuHamu::~HamuHamu()
{
}

void HamuHamu::Init()
{
	//===================================================================
	// ポリゴン初期化
	//===================================================================
	m_spPoly = std::make_shared<KdSquarePolygon>();
	m_spPoly->SetMaterial("Asset/Textures/LessonData/Character/Hamu.png");
	m_spPoly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
}

void HamuHamu::Update()
{
	float moveSpd = 0.05f;
	Math::Vector3 nowPos = m_mWorld.Translation();
	// 移動したい「方向ベクトル」 = 絶対に長さが１でなければならない
	Math::Vector3 moveVec = Math::Vector3::Zero;

	if (GetAsyncKeyState('W') & 0x8000) { moveVec.z = 1.0f; }
	if (GetAsyncKeyState('S') & 0x8000) { moveVec.z = -1.0f; }
	if (GetAsyncKeyState('A') & 0x8000) { moveVec.x = -1.0f; }
	if (GetAsyncKeyState('D') & 0x8000) { moveVec.x = 1.0f; }

	// 正規化
	moveVec.Normalize();
	moveVec *= moveSpd;
	nowPos += moveVec;
	// キャラクターのワールド行列を作る
	m_mWorld = Math::Matrix::CreateTranslation(nowPos);
}

void HamuHamu::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_spPoly, m_mWorld);
}
