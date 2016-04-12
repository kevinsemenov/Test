
#include "Executive.h"

const float REBATE_AMT = 0.035;
const float EXECUTIVE_FEE = 125.00;

Executive::Executive()
{
	rebate = REBATE_AMT;
	fee = EXECUTIVE_FEE;
}

Executive::Executive(string memberName, unsigned int memberID,
		             string memberType, Date membershipExpiration,
					 double totalSpent)
					 : Member(memberName, memberID, memberType,
							  membershipExpiration, totalSpent)
{
	rebate = REBATE_AMT;
	fee = EXECUTIVE_FEE;
}

Executive::~Executive(){}

void Executive::Update()
{

}
