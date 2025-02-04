#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void init() ;
	virtual void update() ;
	virtual void Draw() ;
};