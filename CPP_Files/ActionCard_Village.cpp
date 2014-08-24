#include "ActionCard_Village.h"

ActionCard_Village::ActionCard_Village(std::string cardName)
  : Card(std::string cardName)
{
  type = CardType::Action;
}

ActionCard_Village::play()
{

}
