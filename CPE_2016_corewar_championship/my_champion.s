.name "corewar->NULL"
.comment "just a basic living prog"
.extend

        live %0
get_mem1:
        live %0        
        sti r1, %:f1, %1        
        zjmp    %:get_mem2
get_mem2:
        zjmp    %:f1
f1:     live %0
        fork %:get_mem1
        live %0
        fork %:get_mem2
        live %0
        fork %:get_mem1
        zjmp %:get_mem1
        
