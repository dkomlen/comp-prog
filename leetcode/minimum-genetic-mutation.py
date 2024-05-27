from collections import deque

class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        
        valid = set(bank)
        checked = set({}) # keep track of checked combinations, to avoid loops
        num_muts = 0
        queue = deque([(startGene, 0)])
        

        while queue:
            (start_cand, num_muts) = queue.popleft()
            num_muts += 1
            for i, g in enumerate(start_cand):
                # we mutate every part of the start candidate -> 8 x 3 = 24 combinations
                
                for ng in ['A', 'C', 'G', 'T']:
                    if ng == g:
                        continue
    
                    can_list = list(start_cand)
                    can_list[i] = ng
                    candidate = ''.join(can_list)

                    # check if we found end gene, BFS guarantees min mutations
                    if candidate in valid and candidate == endGene:
                        return num_muts

                    # keep only valid genes
                    if candidate in valid and candidate not in checked:
                        queue.append((candidate, num_muts))
                        checked.add(candidate)

        return -1
