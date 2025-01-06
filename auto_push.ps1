# Configuration
$repoPath = "C:\path\to\your\repository" # Replace with your local repository path
$commitMessage = "Automated commit by PowerShell script"
$pushInterval = 3600 # Interval in seconds (1 hour)

# Change directory to the repository
Set-Location $repoPath

Write-Host "Monitoring directory: $repoPath"

while ($true) {
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
    
    # Wait before the next check (1 hour)
    Start-Sleep -Seconds $pushInterval
}
