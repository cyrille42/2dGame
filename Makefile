NAME = game

SRC = main.cpp src/SDL/Windows.cpp src/Game/Run.cpp src/SDL/Image.cpp \
 src/Game/Menu.cpp src/Player/Player.cpp src/Pve/Entity_alive.cpp  src/Object/Block.cpp \
 src/Object/Background.cpp src/Game/Map.cpp src/Monster/Bat.cpp \
 src/Game/Monster.cpp src/Player/Weapon.cpp src/Object/Bonus_Entity.cpp \
 src/Monster/BatBoss.cpp src/Game/Bonus.cpp src/Monster/Skeleton.cpp \
 src/Weapon/Basic.cpp src/Weapon/Ham.cpp src/Weapon/Bones.cpp

OBJ = $(SRC:.cpp=.o)

HD = src/SDL/Windows.hpp src/Game/Run.hpp src/SDL/Image.hpp \
	src/Game/Menu.hpp src/Player/Player.hpp src/Pve/Entity_alive.hpp src/Object/Block.hpp \
	src/Object/Background.hpp src/Game/Map.hpp src/Monster/Bat.hpp \
	src/Game/Monster.hpp src/Player/Weapon.hpp src/Object/Bonus_Entity.hpp \
	src/Monster/BatBoss.hpp src/Game/Bonus.hpp src/Monster/Skeleton.hpp \
	src/Weapon/Basic.hpp src/Weapon/Ham.hpp src/Weapon/Bones.hpp

all: $(NAME)

#SDL need to be in home path /lib
$(NAME): $(OBJ)
	clang++ -o $@ $^ -L$(HOME)/lib -lSDL2

#linkage
%.o: %.cpp $(HD)
	clang++ -o $@ -c $< -Wall -Werror -Wextra -I $(HOME)/include/ -I./src

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all