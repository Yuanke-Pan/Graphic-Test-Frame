#pragma once

#include<string>
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<unordered_map>

#include"vendor/glm/gtc/matrix_transform.hpp"

struct ShaderSource
{
	std::string VertexShader;
	std::string FragmentShader;
};

class Shader {
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_LocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	void bind() const;
	void unbind()const;

	//set uniform
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v0, float v1,float v2, float v3 );
	void SetUniformMat4(const std::string& name, const glm::mat4& matrix);
private:
	unsigned int GetUniformLocation(const std::string& name);
	unsigned int CompileShader(unsigned int type, const std::string& sources);
	unsigned int CreateShader(const std::string& VertexShader, const std::string& FragmentShader);
	ShaderSource PraseShader(const std::string& FilePath);
};