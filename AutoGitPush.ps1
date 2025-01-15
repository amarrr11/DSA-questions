# Configuration
$repoPath = "C:\Users\Amars\OneDrive\Desktop\DSA\DSA-questions" # Path to your local GitHub repository
$commitMessage = "Automated commit by script"
$pushInterval = 3600 # Interval in seconds (1 hour)

# Change directory to the repository
Set-Location $repoPath

Write-Host "Monitoring directory: $repoPath"

while ($true) {
    try {
        # Check for uncommitted changes
        $status = git status --porcelain
        if ($status) {
            Write-Host "Changes detected. Committing and pushing..."
            git add .
            git commit -m $commitMessage
            git push
            Write-Host "Changes pushed successfully!"
        } else {
            Write-Host "No changes to commit."
        }
    } catch {
        Write-Host "An error occurred: $_"
    }

    # Wait before checking again
    Start-Sleep -Seconds $pushInterval
}
