CALL gds.graph.project(
  'aoc',
  ['S', 'E', 'N'],
  'p'
) 

// Part 1
MATCH (target:E), (source:S)

CALL gds.shortestPath.dijkstra.stream('aoc', {
    sourceNode: source,
    targetNode: target
})
YIELD path
return length(path)

// Part 2

MATCH (target:E), (source{c:'a'})

CALL gds.shortestPath.dijkstra.stream('aoc', {
    sourceNode: source,
    targetNode: target
})
YIELD path
return min(length(path))
