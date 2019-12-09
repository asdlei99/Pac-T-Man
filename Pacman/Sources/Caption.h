#pragma once

#include <vector>

#include "Global.h"

// TODO this can be grouped with dots - same thign technically and also PacMan itself is similar
class Caption
{
public:
  struct InstanceType
  {
    DirectX::XMFLOAT3 position;
    uint8_t sizeFlag;
  };

  Caption();
  ~Caption();

  void Draw(ID3D11DeviceContext1* context);
  void Init(ID3D11Device1* device);

  const DirectX::XMFLOAT4X4& GetWorldMatrix() const { return m_worldMatrix; }

private:
  Microsoft::WRL::ComPtr<ID3D11Buffer>             m_vertexBuffer;
  Microsoft::WRL::ComPtr<ID3D11RasterizerState>    m_cullNone;
  Microsoft::WRL::ComPtr<ID3D11Resource>           m_resource;
  Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_shaderResourceView;
  Microsoft::WRL::ComPtr<ID3D11SamplerState>       m_samplerState;
  Microsoft::WRL::ComPtr<ID3D11BlendState>         m_blendState;
  Microsoft::WRL::ComPtr<ID3D11Buffer>             m_indexBuffer;

  DirectX::XMFLOAT4X4 m_worldMatrix;

  std::vector<Global::Vertex> m_vertices;
  std::vector<uint16_t> m_indices;
};

