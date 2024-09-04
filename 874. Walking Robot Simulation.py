class Solution:

    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:


        directions = (0, 1, 0, -1, 0)


        obstacle_set = {(x, y) for x, y in obstacles}


        max_distance_squared = direction_index = 0

        position_x = position_y = 0



        for command in commands:

            if command == -2:  # Turn left

                direction_index = (direction_index + 3) % 4

            elif command == -1: # Turn right

                direction_index = (direction_index + 1) % 4

            else:


                for _ in range(command):

                    next_x, next_y = position_x + directions[direction_index], position_y + directions[direction_index + 1]


                    if (next_x, next_y) in obstacle_set:

                        break  


                    position_x, position_y = next_x, next_y


                    max_distance_squared = max(max_distance_squared, position_x * position_x + position_y * position_y)

      


        return max_distance_squared