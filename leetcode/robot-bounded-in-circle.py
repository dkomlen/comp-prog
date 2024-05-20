class Solution:

    def isRobotBounded(self, instructions: str) -> bool:
        pos = (0,0)
        direction = 0
        for i in instructions:
            print(pos, direction)
            match(i):
                case "R":
                    direction = (direction + 3) % 12
                case "L":
                    if direction == 0:
                        direction = 9
                    else:
                        direction = (direction - 3) % 12
                case "G":
                    match(direction):
                        case 0:
                            pos = (pos[0], pos[1] + 1)
                        case 3:
                            pos = (pos[0] + 1, pos[1])
                        case 6:
                            pos = (pos[0], pos[1] - 1)
                        case 9:
                            pos = (pos[0] - 1, pos[1])
        
        return pos == (0, 0) or direction != 0
