import matplotlib.pyplot as plt

# Data for each sorting algorithm
data = {
    "Selection": [
        [10000, 0.172483],
        [11000, 0.221947],
        [12000,	0.215714]
        # Add more data points here for Selection sort
    ],
    "Insertion": [
        [10000, 0.172817],
        [11000, 0.214583],
        # Add more data points here for Insertion sort
    ],
    "Merge": [
        [10000, 0.013441],
        [11000, 0.014885],
        # Add more data points here for Merge sort
    ],
    "Quick": [
        [10000, 0.001980],
        [11000, 0.002301],
        # Add more data points here for Quick sort
    ],
    "Heap": [
        [10000, 0.000533],
        [11000, 0.001022],
        # Add more data points here for Heap sort
    ],
    "Counting": [
        [10000, 0.000417],
        [11000, 0.000051],
        # Add more data points here for Counting sort
    ],
}

# Create a separate plot for each sorting algorithm
for algorithm, values in data.items():
    x = [point[0] for point in values]
    y = [point[1] for point in values]

    plt.plot(x, y, label=algorithm)

# Add labels and a legend
plt.xlabel("Input Size (n)")
plt.ylabel("Runtime (s)")
plt.title("Sorting Algorithm Runtimes")
plt.legend()

# Show the plot
plt.show()