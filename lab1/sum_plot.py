import matplotlib.pyplot as plt

# Read only sizes and times from text file
sizes = []
times = []

with open('Sumperformance_data.txt', 'r') as f:
    for line in f:
        parts = line.split()
        # Skip non-data lines
        if len(parts) >= 2 and parts[0].isdigit():
            sizes.append(int(parts[0]))
            times.append(float(parts[1]))

# Create simple plot
plt.figure(figsize=(10, 6))
plt.plot(sizes, times, 'ro-', linewidth=2, markersize=8, 
         markerfacecolor='yellow', markeredgecolor='red')

# Add labels and title
plt.xlabel('Array Size', fontsize=12, fontweight='bold')
plt.ylabel('Execution Time (ms)', fontsize=12, fontweight='bold')
plt.title('Performance Analysis\nArray Sum Algorithm', 
          fontsize=14, fontweight='bold')

# Add grid and customize
plt.grid(True, linestyle='--', alpha=0.6)
plt.xticks(sizes, rotation=45)  # Show all array sizes on x-axis

# Add value labels on points
for i, (size, time) in enumerate(zip(sizes, times)):
    plt.text(size, time, f'{time:.4f}', 
             fontsize=8, ha='center', va='bottom')

plt.tight_layout()
plt.savefig('simple_time_plot.png', dpi=300)
plt.show()

print(f"Plotted {len(sizes)} points")