class ObjOne
{
public:
	ObjOne();
	~ObjOne();

private:
	int m_iCount;
	char m_cSymbol;
};

ObjOne::ObjOne()
{
	m_iCount = 0;
	m_cSymbol = 'a';
}

ObjOne::~ObjOne()
{
}