
#include "Member.h"

const float MEMBER_FEE = 45.00;

Member::Member()
{
	name.clear();
	id = 0;
	type.clear();
	expiration.SetDate(0,0,0);
	spent = 0.0;
	fee = MEMBER_FEE;
}

Member::Member(string memberName, unsigned int memberID, string memberType,
			   Date membershipExpiration, double totalSpent)
{
	name = memberName;
	id = memberID;
	type = memberType;
	expiration = membershipExpiration;
	spent = totalSpent;
	fee = MEMBER_FEE;
}

Member::~Member(){}

void Member::SetName(string memberName)
{
	name = memberName;
}

void Member::SetID(unsigned int memberID)
{
	id = memberID;
}

void Member::SetType(string memberType)
{
	type = memberType;
}

void Member::SetExpiration(Date membershipExpiration)
{
	expiration = membershipExpiration;
}

void Member::SetSpent(double totalSpent)
{
	spent = totalSpent;
}

string Member::GetName() const
{
	return name;
}

unsigned int Member::GetID() const
{
	return id;
}

string Member::GetType() const
{
	return type;
}

Date Member::GetExpiration() const
{
	return expiration;
}

double Member::GetSpent() const
{
	return spent;
}

void Member::Update()
{

}
