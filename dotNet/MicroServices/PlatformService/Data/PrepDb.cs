using PlatformService.Models;
namespace PlatformService.Data
{
    public static class PrepDb
    {
        private static void SeedData(AppDbContext context)
        {
            if(!context.Platforms.Any())
            {
                Console.WriteLine("Seeding Data...");
                context.Platforms.AddRange(
                    new Platform(){Name="Dot Net", Publisher="Microsoft",Cost="Free"},
                    new Platform(){Name="Test1Name", Publisher="Test1Publisher",Cost="Free"},
                    new Platform(){Name="Test2Name", Publisher="Test2Publisher",Cost="Free"}
                );

                context.SaveChanges();
            }
            else
            {
                Console.WriteLine("Already have data");
            }
        }
        public static void PrepPopulation(IApplicationBuilder app)
        {
            using( var serviceScope = app.ApplicationServices.CreateScope())
            {
                SeedData(serviceScope.ServiceProvider.GetService<AppDbContext>());
            }
        }
            
    }
}
