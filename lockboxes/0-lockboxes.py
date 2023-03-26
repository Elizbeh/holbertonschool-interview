def canUnlockAll(boxes):
    boxes_opened = {0}
    
    next_to_open = [0]
    
    while len(next_to_open) > 0:
        box = next_to_open.pop(0)
        
        for key in boxes[box]:
          if key not in boxes_opened and key < len(boxes):
                next_to_open.append(key)
                boxes_opened.add(key)
    
    return len(boxes_opened) == len(boxes)